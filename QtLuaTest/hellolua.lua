function sleep(n)
    if n > 0 then os.execute("ping -n " .. tonumber(n + 1) .. " localhost > NUL") end
 end

-- days = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"}
-- for i,v in ipairs(days) do  print(v) Sleep(2) end

print("=====0123456789=====")

local hello1
local hello2
local hello3
local hello4

hello1, hello2, hello3, hello4 = openLight(1, 2, 3)
print(hello1)
print(hello2)
print(hello3)
print(hello4)

local a=0
while( a < 20 )
do
   local ret = waitforData()
   if (ret) then
      print("true" )
   else
      print("false" )
   end
end
