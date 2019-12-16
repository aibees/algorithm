arr = [0] * 5
for i in range(5) :
    arr[i] = int(input())
arr.sort()
avg = sum(arr) // 5
print(avg)
print(arr[2])
