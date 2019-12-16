import itertools

n = int(input())

pool = list(range(1, n+1))

def mapFunc(data) :
    tmp = list(data)
    tmp.append(data[0])
    print(tmp)

print(list(map(mapFunc, itertools.permutations(pool))))
