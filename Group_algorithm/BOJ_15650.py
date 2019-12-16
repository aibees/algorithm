import itertools

def func(item) :
    i_list = sorted(list(item))
    s = ""
    for i in i_list :
        s += str(i)
        s += " "
    return s

n, m = list(map(int, input().split(" ")))
num = list(range(1, n+1))
result = list(map(func, itertools.permutations(num, m)))
result = sorted(list(set(result)))
for i in result :
    print(i)