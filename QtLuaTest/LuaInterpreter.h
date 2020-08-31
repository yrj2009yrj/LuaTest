#ifndef __LUAINTERPRETER_H__
#define __LUAINTERPRETER_H__

#include <QObject>

#include <lua.hpp>

class QMutex;
class QWaitCondition;

class LuaInterpreter : public QObject
{
    Q_OBJECT
public:

public:
    LuaInterpreter(QObject* parent=nullptr);

    ~LuaInterpreter();

    LuaInterpreter(const LuaInterpreter&) = delete;

    LuaInterpreter& operator = (const LuaInterpreter&) = delete;

    static LuaInterpreter* getInstance();
    
    void init();
    
    int notifyforData();

    void doFile(QString);


    static int openLight(lua_State*);

    static int waitforData(lua_State*);



private:
    lua_State* luaState;

    static QMutex* mutex;
    static QWaitCondition* waitCondition;
    static LuaInterpreter* instance;
};

#endif
