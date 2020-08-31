#include <iostream>

#include <thread>
#include <chrono>

#include <lua.hpp>

lua_State *L;

static int frist_lua(lua_State * L)
{
    lua_Number num1 = lua_tonumber(L, 1);
    lua_Number num2 = lua_tonumber(L, 2);
    lua_Number num3 = lua_tonumber(L, 3);

    //std::this_thread::sleep_for(std::chrono::seconds(5));

    std::cout << num1 << std::endl; 
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;
    lua_pushstring(L, "Hello Lua");
    return 100;
}

int main(int argc, char * argv[])
{
    L = luaL_newstate();   //注册一个状态机
    luaL_openlibs(L);    //加载lua库

    lua_register(L, "frist_lua", frist_lua);
    lua_pushstring(L, "Hello Lua");
    luaL_dofile(L, "hellolua.lua");   //加载lua脚本
    
    //if (luaL_loadfile(L, "hellolua.lua") || lua_pcall(L, 0, 0, 0)) {     // 执行栈顶函数，0个参数、0个返回值、无出错处理函数（出错时直接把错误信息压栈）
    //    std::cout << "lua load file error" << std::endl;
    //}

    lua_close(L);   //释放虚拟机
    getchar();
    return 0;
}
