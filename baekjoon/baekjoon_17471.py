n = int(input())
graph = {}
pem = []
people = list(map(int, input().split(" ")))
vertice = list(range(1, n+1))
answer = -1

# get vertex graph line
for i in range(len(people)) :
    line = list(map(int, input().split(" ")))[1:]
    graph[i+1] = line

def cal_people(vertx) :
    result = 0
    for v in vertx :
        result += people[v-1]
    return result

def validation(li) :
    visited = [li[0]]
    queue = [li[0]]

    while queue :
        cur = queue.pop(0)
        cur_li = []
        if cur in graph :
            cur_li = graph[cur]
        
        for vertex in cur_li :
            if vertex not in visited and vertex in li :
                queue.append(vertex)
                visited.append(vertex)
    
    if list(set(visited)).sort() is li.sort() :
        return True
    else :
        return False

for com_cnt in range(1, n//2 + 1) :
    print(com_cnt)
    print(pem)
    if com_cnt is 1 :
        for v in vertice :
            first_ = [v]; second_ = vertice[:]
            pem.append(first_)
            for f in first_ :
                second_.remove(f)
            print("==================")
            print("first : ", first_)
            print("second : ", second_)
            if validation(first_) and validation(second_) :
                f_sum = cal_people(first_)
                s_sum = cal_people(second_)
                diff = abs(f_sum - s_sum)
                if answer is -1 or answer > diff :
                    answer = diff

    elif com_cnt > 1 :
        pem_size = len(pem)
        print(pem_size)
        for i in range(pem_size) :
            first_ = pem.pop(0)
            last_v = first_[len(first_)-1]
            print("\nbefore first_ : ", first_, "last_v : ", last_v)
            for v in range(last_v+1, n+1) :
                tmp = first_[:]
                tmp.append(v)
                print("after append : ", tmp)
                pem.append(tmp)
                print("after append pem : ")
                print(pem)
                second_ = vertice[:]
                for f in tmp :
                    second_.remove(f)

                print("==================")
                print("first : ", tmp)
                print("second : ", second_)
                if validation(tmp) and validation(second_) :
                    f_sum = cal_people(tmp)
                    s_sum = cal_people(second_)
                    diff = abs(f_sum - s_sum)
                    if answer is -1 or answer > diff :
                        answer = diff
print(answer)