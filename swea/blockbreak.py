T = int(input())

for test_case in range(1, T+1) :
    n, w, h = map(int, input().split(" "))
    graph = [[0] * w for i in range(h)]
    for i in range(h) :
        graph[i] = list(map(int, input().split(" ")))
    # 입력 완료

    
