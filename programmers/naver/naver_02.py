import math

def solution(n) :
    answer = 0
    tmp = [2]
    if n is 1 :
        answer = 2
    elif n is 2 :
        answer = 6
    else :
        for i in range(3, n*(n+1)//2) :
            for j in range(1, i-1) :
                res = math.factorial(i) // math.factorial(j)
                if res <= 1000000 * 1000000 :
                    tmp.append(res)
        tmp = list(set(tmp))
        tmp.sort()
        print(tmp)
        answer = tmp[n-1]

    return answer

print(solution(9))