import itertools

def func(item) :
    i_list = list(map(str, sorted(list(item))))
    s = " ".join(i_list)
    return s

n, m = list(map(int, input().split(" ")))
num = list(range(1, n+1))
result = list(map(func, itertools.product(num, repeat=m)))
result = sorted(list(set(result)))
for i in result :
    print(i)