#include <iostream>

#include <thread>
#include <chrono>

#include <lua.hpp>

#include <cstdio>

lua_State *L;

static void stackDump(lua_State* L) //打印整个栈的内容，由下而上，根据元素类型打印
{
    int top = lua_gettop(L);    //返回栈顶元素的索引。 因为索引是从 1 开始编号的，
                                //所以这个结果等于栈上的元素个数； 特别指出，0 表示栈为空
    for (int i = 1; i <= top; ++i) {
        int t = lua_type(L, i); //返回给定有效索引处值的类型，
                                //当索引无效（或无法访问）时则返回 LUA_TNONE
        switch (t) {
            case LUA_TSTRING:
                printf("'%s'", lua_tostring(L, i));
                break;
            case LUA_TBOOLEAN:
                printf(lua_toboolean(L, i) ? "true" : "false");
                break;
            case LUA_TNUMBER:
                printf("%g", lua_tonumber(L, i));
                break;
            default:
                printf("%s", lua_typename(L, t));   //返回 t 表示的类型名，
                                                    //这个 tp 必须是 lua_type 可能返回的值中之一。
                break;
        }
        printf("");
    }
    printf("\n");
 }

static int frist_lua(lua_State * L)
{
    lua_Number num1 = lua_tonumber(L, 1);
    lua_Number num2 = lua_tonumber(L, 2);
    const char* num3 = lua_tostring(L, 3);

    //std::this_thread::sleep_for(std::chrono::seconds(5));

    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;

    lua_pushstring(L, "Hello 1");
    lua_pushstring(L, "Hello 2");
    return 2;
}

using namespace std;

int main(int argc, char * argv[])
{
    //1.创建Lua状态
    lua_State* L = luaL_newstate();
    if (L == NULL)
    {
        return 0;
    }

    //2.加载Lua文件
    int bRet = luaL_loadfile(L, "hellolua.lua");
    if (bRet)
    {
        cout << "load file error" << endl;
        return 0;
    }

    //3.运行Lua文件
    bRet = lua_pcall(L, 0, 0, 0);
    if (bRet)
    {
        cout << "pcall error" << endl;
        return 0;
    }

    std::string cmd_str = "str = \"ooooooooooooo\"";
    luaL_dostring(L, cmd_str.c_str());

    //4.读取变量
    lua_getglobal(L, "str");
    string str = lua_tostring(L, -1);
    cout << "str = " << str.c_str() << endl;        //str = I am so cool~

    //5.读取table
    lua_getglobal(L, "tbl");
    lua_getfield(L, -1, "name");
    str = lua_tostring(L, -1);
    cout << "tbl:name = " << str.c_str() << endl;   //tbl:name = shun

    //6.读取函数
    lua_getglobal(L, "add");            // 获取函数，压入栈中
    lua_pushnumber(L, 10);              // 压入第一个参数
    lua_pushnumber(L, 20);              // 压入第二个参数
    int iRet = lua_pcall(L, 2, 1, 0);   // 调用函数，调用完成以后，会将返回值压入栈中，2表示参数个数，1表示返回结果个数。
    if (iRet)                           // 调用出错
    {
        const char* pErrorMsg = lua_tostring(L, -1);
        cout << pErrorMsg << endl;
        lua_close(L);
        return 0;
    }
    if (lua_isnumber(L, -1))            //取值输出
    {
        double fValue = lua_tonumber(L, -1);
        cout << "Result is " << fValue << endl;
    }

    //至此，栈中的情况是：
    //=================== 栈顶 ===================
    //  索引  类型      值
    //   4   int：      30
    //   3   string：   shun
    //   2   table:     tbl
    //   1   string:    I am so cool~
    //=================== 栈底 ===================

    //7.关闭state
    lua_close(L);

    return 0;
}
