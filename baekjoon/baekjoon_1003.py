num = int(input())
Q = list(int(input()) for i in range(num))
ar = [[0]*2 for x in range(41)]
ar[0][0] = 1;ar[0][1] = 0;ar[1][0] = 0;ar[1][1] = 1
for i in range(2, 41) :
    ar[i][0] = ar[i-1][0] + ar[i-2][0]
    ar[i][1] = ar[i-1][1] + ar[i-2][1]

for i in Q :
    print(str(ar[i][0]) + " " + str(ar[i][1]))