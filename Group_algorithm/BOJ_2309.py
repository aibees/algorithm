from itertools import combinations

small = [0] * 9
for i in range(9) :
    small[i] = int(input())
s = sum(small)
comb_list = list(map(list, combinations(small, 2)))
result_item = []
for item in comb_list :
    result = s - item[0] - item[1]
    if result is 100 :
        result_item = item
        break
small.remove(result_item[0])
small.remove(result_item[1])
small.sort()
for i in small :
    print(i)