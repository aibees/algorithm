# 점화식
# 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, ....

num = int(input())

def solution(num) :
    start = 1
    if num <= 2 :
        return start
    else :
        while((start * (start + 1) / 2) <= num) :
            start = start + 1
        return start-1


print(solution(num))