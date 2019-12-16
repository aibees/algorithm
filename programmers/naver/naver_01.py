def solution(order):
    answer = []
    tmp_answer = []

    for x in order :
        if x.startswith("RECEIVE") :
            mail = list(x.split(" "))[1]
            tmp_answer.append(mail)
        elif x is "DELETE" :
            if len(tmp_answer) > 0 :
                tmp_answer.pop()
        elif x is "SAVE" :
            answer.extend(tmp_answer)
            tmp_answer = []

    return answer

print(solution(["RECEIVE qwt0326@naver.com", "RECEIVE aibees1129@naver.com", "DELETE", "RECEIVE qwerty@naver.com", "SAVE"]))