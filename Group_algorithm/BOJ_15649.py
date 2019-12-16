import itertools

def func(item) :
    s = ""
    for i in item :
        s += str(i)
        s += " "
    return s

n, m = list(map(int, input().split(" ")))
num = list(range(1, n+1))
result = list(map(func, itertools.permutations(num, m)))

for i in result :
    print(i)