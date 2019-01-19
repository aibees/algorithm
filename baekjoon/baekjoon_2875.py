n, m, k = map(int, input().split())
""" team = 0
if k > n+m:
    print(0)
else :
    if (n//2) < m :
        team = n//2
    else :
        team = m
    k -= (n + m - team*3)

    if k > 0 :
        team -= ((k+2)//3)

print(team)
 """
print(min(n//2, m, (m+n-k)//3))

# 마지막 한 줄이면 끝나는 걸 나는 15줄을 소비하는 이 한심함...