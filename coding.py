n = int(input())
holder = 1
flag = 0
line = input()
ls = "*"
for i in line:
    if(i == 'S'):
        ls = ls + "S*"
        holder = holder + 1
    elif(i == 'L' and flag == 0):
        ls = ls + "L"
        flag = 1
        continue
    elif(i == 'L' and flag == 1):
        ls = ls + "L*"
        holder = holder + 1
        flag = 0

if holder <= n:
    print(holder)
else:
    print(n)