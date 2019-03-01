from itertools import permutations
n = int(input())
m = permutations(range(1, n+1))
for i in m :
    tmp = ""
    for j in i :
        tmp += str(j)
        tmp += " "
    print(tmp)