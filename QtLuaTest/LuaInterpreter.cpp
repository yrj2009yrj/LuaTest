#include "LuaInterpreter.h"

#include <QtConcurrent/QtConcurrent>
#include <QtCore/QDebug>
#include <QtCore/QMutex>
#include <QtCore/QMutexLocker>
#include <QtCore/QWaitcondition>

QMutex* LuaInterpreter::mutex = new QMutex();
QWaitCondition* LuaInterpreter::waitCondition = new QWaitCondition();
LuaInterpreter* LuaInterpreter::instance = LuaInterpreter::getInstance();

LuaInterpreter::LuaInterpreter(QObject* parent)
    : QObject(parent)
{
    luaState = luaL_newstate(); //ע��һ��״̬��
    luaL_openlibs(luaState);    //����lua��
}

LuaInterpreter::~LuaInterpreter()
{
    lua_close(luaState);    //�ͷ������

    delete mutex;
    delete waitCondition;
}

LuaInterpreter* LuaInterpreter::getInstance()
{
    static LuaInterpreter lua_interpreter;
    return &lua_interpreter;
}

int LuaInterpreter::openLight(lua_State* lua_state)
{
    int num1 = lua_tonumber(lua_state, 1);
    int num2 = lua_tonumber(lua_state, 2);
    int num3 = lua_tonumber(lua_state, 3);
    qDebug() << num1 << num2 << num3;
    lua_pushstring(lua_state, "Hello Lua 11111");
    lua_pushstring(lua_state, "Hello Lua 22222");
    lua_pushstring(lua_state, "Hello Lua 33333");
    lua_pushstring(lua_state, "Hello Lua 44444");
    return 4;
}

int LuaInterpreter::waitforData(lua_State* lua_state)
{
    QMutexLocker locker(mutex);
    if (waitCondition->wait(mutex, 5000)) {
        lua_pushboolean(lua_state, true);
    }
    else {
        lua_pushboolean(lua_state, false);
    }
    return 1;
}

int LuaInterpreter::notifyforData()
{
    QMutexLocker locker(mutex);
    waitCondition->wakeOne();
    return 0;
}

void LuaInterpreter::init()
{
    luaL_openlibs(luaState);    //����lua��
    lua_register(luaState, "openLight", openLight);
    lua_register(luaState, "waitforData", waitforData);
}

void LuaInterpreter::doFile(QString file)
{
    QtConcurrent::run([=](){
        qDebug() << file << luaState;
        if (luaL_dofile(luaState, file.toLatin1().data())) {
            qDebug() << "lua do file error";
        }
    });
}
