def calcDistance(x, y) :
    if y >= x : return y - x
    else : return (y + 26) - x

n = int(input())

for i in range(n) :
    c = list()
    a, b = input().split(" ")
    for x, y in zip(a, b) : 
        c.append(str(calcDistance(ord(x) - 64, ord(y) - 64)))
    print("Distances:", " ".join(c))