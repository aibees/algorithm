numSet = [0] * 9
n_list = list(map(int, list(str(input()))))
answer = 0
for i in n_list :
    if i is 9 :
        numSet[6] += 1
    else :
        numSet[i] += 1

tmp = numSet[6]
numSet[6] = (tmp // 2)
if tmp % 2 == 1 :
    numSet[6] += 1

for cnt in numSet :
    if answer < cnt :
        answer = cnt

print(answer)