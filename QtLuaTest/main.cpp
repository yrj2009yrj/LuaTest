#include <QtCore/QCoreApplication>

#include <QtCore/QThread>

#include "LuaInterpreter.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    LuaInterpreter::getInstance()->init();
    LuaInterpreter::getInstance()->doFile("hellolua.lua");

    for (int i = 0; i < 20; ++i) {
        QThread::sleep(2);
        LuaInterpreter::getInstance()->notifyforData();
    }

    return a.exec();
}
