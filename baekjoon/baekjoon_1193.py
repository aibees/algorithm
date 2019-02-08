n = int(input())
a = 1;sum = 0; tmp = 0
while(True) :
    sum = sum + a
    a = a + 1
    if sum >= n :
        a = a - 1
        sum = sum - a
        break

tmp = n - sum
up = 0; down = 0
if a == 1 :
  up = 1; down = 1  
elif a % 2 == 1 :
    up = a;down = 1
    for i in range(tmp-1) :
        up = up - 1
        down = down + 1
else :
    up = 1;down = a
    for i in range(tmp-1) :
        up = up + 1
        down = down - 1

if n == 1 :
    print("1/1")
else : 
    print(str(up)+'/'+str(down))