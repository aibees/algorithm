def solution(cook_times, order, k) :
    graph = {}
    cnt = 0
    time = 0

    for i in order :
        before = i[0]
        after = i[1]
        if after not in graph :
            graph[after] = [before]
        else :
            tmp_list = graph[after]
            tmp_list.append(before)
            graph[after] = tmp_list
    
    queue = [k]
    visited = [k]
    while queue :
        tmp_ = []
        for item in queue :
            if item in graph :
                li = graph[item]
                for x in li :
                    tmp_.append(x)
        tmp_ = list(set(tmp_))
        for r in tmp_ :
            if r in queue :
                queue.remove(r)
                visited.remove(r)
        q_size = len(queue)
        for j in queue :
            time += cook_times[j-1]
        for i in range(q_size) :
            if len(queue) > 0 :
                cur = queue.pop(0)
            else :
                continue
            if cur not in graph :
                continue
            li = graph[cur]
            for w in li :
                if w not in visited :
                    visited.append(w)
                    queue.append(w)

    cnt = len(visited) - 1
    return [cnt, time]

print(solution([5, 3, 2], [[1, 3], [2, 3], [1, 2]], 3))