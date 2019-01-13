n = int(input())
a = list(int(input()) for i in range(n))
a.sort(reverse = True)
max = 0
cnt = 0
for i in a :
    cnt = cnt+1
    if max < (i * cnt) :
        max = i * cnt

print(max)

