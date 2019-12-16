import copy, sys

n = int(input())
maps = [[0] * n for i in range(n)]
visited = [[0] * n for i in range(n)]
q = []
stk = []
# 위 왼쪽 아래 오른쪽
nX = [0, -1, 0, 1]
nY = [-1, 0, 1, 0]

for i in range(n) :
    maps[i] = list(map(int, input().split(" ")))

def dfs() :
    while stk :
        cur = stk.pop()
        cnt = cur[2]
        for k in range(4) :
            nextX = nX[k] + cur[0]
            nextY = nY[k] + cur[1]

            if nextX < 0 or nextX >= n or nextY < 0 or nextY >= n :
                continue
        
            if visited[nextX][nextY] is 0 and maps[nextX][nextY] is 1 :
                visited[nextX][nextY] = 1
                q.append((nextX, nextY, cnt))
                stk.append((nextX, nextY, cnt))

# island numbering
count = 1
for i in range(n) :
    for j in range(n) :
        if maps[i][j] is not 0 and visited[i][j] is 0 :
            visited[i][j] = 1
            q.append((i, j, count))
            stk.append((i, j, count))
            dfs()
            count += 1

ans = n*n
length = 0
while q :
    cur = q.pop(0)
    tmp_q = copy.deepcopy(q)
    while tmp_q :
        tmp = tmp_q.pop(0)
        if cur[2] is tmp[2] :
            continue
        else :
            length = abs(cur[0] - tmp[0]) + abs(cur[1] - tmp[1]) - 1
            if ans > length :
                ans = length
print(ans)