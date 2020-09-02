function sleep(n)
    if n > 0 then os.execute("ping -n " .. tonumber(n + 1) .. " localhost > NUL") end
end

days = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"}
for i,v in ipairs(days)
do
   print(v)
   sleep(1)
end

print("===== ***** ===== ***** ===== ***** =====")

local hello1
local hello2

hello1, hello2 = openLight(1, 2, 3)
print(hello1)
print(hello2)

flag = true
local a = 0
while( flag )
do
   local ret = waitforData()
   if (ret) then
      print("true" )
   else
      print("false" )
   end
   a = a+1
end

print("***** ===== ***** ===== ***** ===== *****")
