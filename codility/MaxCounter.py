def solution(N, A):
    answer = [0] * N
    mx = 0
    mxtmp = 0

    for i in A :
        if i == N + 1 :
            mx = mxtmp
        else :
            tmp = answer[i-1]
            if tmp < mx :
                answer[i-1] = mx + 1
            else :
                answer[i-1] = tmp + 1
            if mxtmp < answer[i-1] :
                mxtmp = answer[i-1]

    for i in range(N) :
        if answer[i] < mx :
            answer[i] = mx

    return answer

ret = solution(5, [3, 4, 4, 6, 1, 4, 4])
print(ret)