def find(vertex) :
    dist = 0
    while vertex is not parent[vertex] and parent[vertex] is not 0 :
        tmp = abs(vertex - parent[vertex])
        # print("tmp : ", tmp)
        if tmp > 1000 :
            tmp = tmp % 1000
        dist += tmp
        vertex = parent[vertex]
    return dist

def merge(src, des) :
    root1 = parent[src]
    root2 = parent[des]

    if root1 is not root2 :
        if set_size[root1] < set_size[root2] :
            tmp = root2
            root2 = root1
            root1 = tmp

        parent[root1] = root2
        set_size[root2] += set_size[root1]
        set_size[root1] = 0

T = int(input())
for i in range(T) :
    num = int(input())
    parent = [0] * (num+1)
    set_size = [0] * (num+1)
    orders = []
    while True :
        o = list(input().split(" "))
        orders.append(o)
        if o[0] is 'O' :
            break
    while True :
        order = orders.pop(0)
        if order[0] is 'O' :
            break
        elif order[0] is 'E' :
            # print("num : ", int(order[1]))
            print(find(int(order[1])))
        elif order[0] is 'I' :
            if parent[int(order[1])] is 0 :
                parent[int(order[1])] = int(order[1])
            if parent[int(order[2])] is 0 :
                parent[int(order[2])] = int(order[2])
            # print("before parent : ", parent)
            merge(int(order[1]), int(order[2]))
            # print("after  parent : ", parent)