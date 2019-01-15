def isNumber(s) :
    try:
        float(s)
        return True
    except ValueError:
        return False

n = int(input())
guitar = []
for i in range(n) :
    a = input()
    c = 0
    for j in a :
        if isNumber(j) :
            c = c + int(j)
    guitar.append((len(a), c, a))
#sort
guitar.sort() # sort() 함수 사용 시 가장 뒤에 있는 원소들부터 정렬해간다
for i in range(len(guitar)) :
    print(guitar[i][2])
