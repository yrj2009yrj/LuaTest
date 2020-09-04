function sleep(n)
    if n > 0 then os.execute("ping -n " .. tonumber(n + 1) .. " localhost > NUL") end
end

-- days = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"}
-- for i,v in ipairs(days)
-- do
--    print(v)
--    sleep(1)
-- end

-- print("===== ***** ===== ***** ===== ***** =====")

-- local hello1
-- local hello2

-- hello1, hello2 = openLight(1, 2, 3)
-- print(hello1)
-- print(hello2)

-- flag = true
-- local a = 0
-- while( flag )
-- do
--    local ret = waitforData()
--    if (ret) then
--       print("true" )
--    else
--       print("false" )
--    end
--    a = a+1
-- end

-- print("***** ===== ***** ===== ***** ===== *****")

-----------------------------------------------------
-- local co = coroutine.create(function ()
--    for i = 1, 200 do
--         print("co", i)
--         coroutine.yield()
--    end
-- end)

-- coroutine.resume(co)     -- 打印co 1

-- print(coroutine.status(co))     -- suspended

-- function toLive()
--    coroutine.resume(co)
-- end

-----------------------------------------------------
-- function values(tb)
--    local i = 0
--    return function ()
--         i = i + 1
--         return tb[i]
--    end
-- end

-- local testTb = {10, 20, 30}
-- for value in values(testTb) do
--    print(value)
-- end

-----------------------------------------------------
-- function foo (a)
--    print("foo", a)  -- foo 2
--    return coroutine.yield(2 * a) -- return 2 * a
-- end

-- co = coroutine.create(function (a , b)
--    print("co-body", a, b) -- co-body 1 10
--    local r = foo(a + 1)

--    print("co-body2", r)
--    local r, s = coroutine.yield(a + b, a - b)

--    print("co-body3", r, s)
--    return b, "end"
-- end)

-- print("main", coroutine.resume(co, 1, 10)) -- true, 4
-- print("------")
-- print("main", coroutine.resume(co, "r")) -- true 11 -9
-- print("------")
-- print("main", coroutine.resume(co, "x", "y")) -- true 10 end
-- print("------")
-- print("main", coroutine.resume(co, "x", "y")) -- false cannot resume dead coroutine
-- print("------")

-----------------------------------------------------
print(getmetatable("Hello World"))
print(getmetatable(10))
