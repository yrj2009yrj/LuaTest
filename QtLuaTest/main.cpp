#include <QtCore/QCoreApplication>

#include <QtCore/QThread>

#include "LuaInterpreter.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    LuaInterpreter::getInstance()->init();
    LuaInterpreter::getInstance()->doFile("hellolua.lua");

    for (int i = 0; i < 200; ++i) {
        QThread::sleep(2);
        LuaInterpreter::getInstance()->doString();
    }

    return a.exec();
}
