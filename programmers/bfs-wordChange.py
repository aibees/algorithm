graph = {}

def solution(begin, target, words):
    if target not in words :
        return 0

    for word in words :
        if word not in graph :
            graph[word] = []

    for one in words :
        for two in words :
            cnt = 0
            if one is not two :
                for x, y in zip(one, two) :
                    if x is not y :
                        cnt += 1
            if cnt is 1 :
                tmp = graph[one]
                tmp.append(two)
                graph[one] = tmp

    return dfs(begin, target, words)

def dfs(start, target, words) :
    cnt = 0
    stk = []
    visited = []

    for w in words :
        c = 0
        for x, y in zip("hit", w) :
            if x is not y :
                c += 1
        if c is 1 :
            stk.append(w)

    if len(stk) is 0 : return 0
    cnt += 1

    while stk :
        print("stk : ", stk)
        print("visited : ", visited)
        print("count : ", cnt)
        item = stk.pop()
        if item is target :
            break
        
        if item not in visited :
            visited.append(item)
            li = graph[item]
            cnt += 1
            for w in li :
                if w not in stk and w not in visited :
                    stk.append(w)
    return cnt

print(solution("hit", "cog", ["hot", "dot", "dog", "lot", "log", "cog"]))