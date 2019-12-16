a = int(input())
b = int(input())
c = int(input())
arr = [0]*10
result = str(a*b*c)
for num in result :
    arr[int(num)] += 1

for i in arr :
    print(i)