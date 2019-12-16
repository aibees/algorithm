des = input()
des_list = list(map(int, des))
n = int(input())
button = ['+', '-']
numbers = list(map(int, range(10)))
ex = list(input().split(" "))
for i in ex :
    if i is not '+' or i is not '-' :
        numbers.remove(int(i))
    else :
        button.remove(i)
print(des_list)
print(button)
print(numbers)

# 일단 목표 숫자에 가깝게 접근
def search(num) :
    target = 0
    first = 0; last = len(numbers)-1
    if numbers[first] >= num :
        return numbers[first]
    if numbers[last] <= num :
        return numbers[last]
    while first <= last and last - first > 1 :
        middle = (first + last) // 2
        if numbers[middle] > num :
            last = middle
            continue
        elif numbers[middle] < num :
            first = middle
            continue
        else :
            target = numbers[middle]
            return target
    if abs(first - num) > abs(last - num) :
        target = numbers[last]
    else :
        target = numbers[first]
    return target
tmp = []
for i in des_list :
    tmp.append(search(i))
tmp = list(map(str, tmp))
print(tmp)
print(int(''.join(tmp)))