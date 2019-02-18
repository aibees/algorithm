n = int(input())
ar = list(map(int, input().split()))

dp = [[0]*21 for i in range(n)]
dp[0][ar[0]] = 1
for i in range(1, n) :
    for j in range(0, 21) :
        if dp[i-1][j] != 0 :
            if j - ar[i] >= 0 :
                dp[i][j-ar[i]] = dp[i][j-ar[i]] + dp[i-1][j]
            if j + ar[i] <= 20 :
                dp[i][j+ar[i]] = dp[i][j+ar[i]] + dp[i-1][j]

print(dp[n-2][ar[-1]])