N, Q = map(int, input().split(' '))
arr = [*map(int, input().split(' '))]
for i in range(Q) :
    query = [*map(int, input().split(' '))]
    if query[0] == 1 :
        for j in range(query[1]-1, query[2]) :
            arr[j] = query[3]
    elif query[0] == 2 :
        tmp = 1
        for j in range(query[1]-1, query[2]) :
            arr[j] += (query[3]*tmp)
            tmp += 1
    elif query[0] == 3 :
        arr.insert(query[1], query[2])
    else :
        num = 0
        for j in range(query[1]-1, query[2]) :
            num += arr[j]
        print(num)

