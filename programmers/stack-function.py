def solution(progresses, speeds):
    answer = []
    success = []
    for i in range(len(progresses)) :
        tmp = (100 - progresses[i])//speeds[i]
        success.append(tmp if (100 - progresses[i])%speeds[i] is 0 else tmp + 1)
    a = success[0]
    cnt = 0
    for i in success :
        if i > a :
            answer.append(cnt)
            cnt = 1
            a = i
        else :
            cnt+=1
    answer.append(cnt)
    return answer