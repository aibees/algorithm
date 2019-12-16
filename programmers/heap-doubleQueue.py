import heapq

def solution(operations):
    queue = []
    for oper in operations :
        print(oper)
        if oper.startswith("D") :
            num = int(list(oper.split(" "))[1])
            if num is 1 and len(queue) is not 0 :
                queue.pop()
            elif num is -1 and len(queue) is not 0 :
                queue.pop(0)
        elif oper.startswith('I') :
            queue.append(int(list(oper.split(" "))[1]))
            queue = sorted(queue)
        print(queue)
    
    if len(queue) is 0 :
        answer = [0,0]
    else :
        answer = [queue.pop(), queue.pop(0)]
    return answer

print(solution(	["I -45", "I -642", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"]))