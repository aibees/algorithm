from functools import reduce

def isNum(i) :
    try:
        float(i)
        return True
    except ValueError:
        return False
li = []
for i in range(int(input())) :
    n = [];num = "";flag = False
    for i in input() :
        if isNum(i) : # 숫자일 때
            if flag is False :
                flag = True
            if flag :
                num += i
        else : # 숫자가 아닐 때
            if flag is True :
                flag = False
            if num is not "" :
                n.append(int(num))
                num = ""
    if num is not "" :
        n.append(int(num))
        num = ""
    li.extend(n)
li.sort()
for i in li :
    print(i)