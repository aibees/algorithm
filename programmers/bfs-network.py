import copy

network = {}
num_list = None

def solution(n, computers):
    answer = 0; x = 0
    num_list = list(range(n))
    
    for data in computers :
        tmp_list = []; tmp = 0
        for d in data :
            if d is 1 and x is not tmp :
                tmp_list.append(tmp)
            tmp += 1
        network[x] = tmp_list
        x += 1
    
    while len(num_list) > 0 :
        visited = dfs(num_list[0])
        for n in visited :
            num_list.remove(n)
        answer += 1
    return answer

def dfs(start) :
    visited = [start]
    queue = [start]
    while queue :
        n = queue.pop(0)
        li = network[n]
        for d in li :
            if d not in visited :
                visited.append(d)
                queue.append(d)
    return visited


print(solution(3, [[1, 1, 0], [1, 1, 0], [0, 0, 1]]))