n, k = map(int, input().split(" "))
oven = list(map(int, input().split(" ")))
pizza = list(map(int, input().split(" ")))
cur = 10000000000

tmp = []
for item in oven :
    if cur > item :
        cur = item
    tmp.append(cur)

result = len(oven)
dough = pizza.pop(0)
for i in range(len(tmp)-1, -1, -1) :
    # print("==== start ", i, " ====")
    # print("oven : ", oven)
    # print("radius : ", tmp)
    # print("result : ", result)
    if i is not len(tmp)-1 and dough <= tmp[i] and oven[i+1] is -1 : # 바로 전 위치에 도우가 들어가 있다
        oven[i] = -1
        result = i+1
        if len(pizza) > 0 :
            dough = pizza.pop(0)
            continue
        else :
            break

    if dough > tmp[i] :
        continue
    else :
        oven[i] = -1
        result = i+1
        if len(pizza) > 0 :
            dough = pizza.pop(0)
        else :
            break

# print("oven : ", oven)
# print("radius : ", tmp)
# print("result : ", result)
    
print(result)