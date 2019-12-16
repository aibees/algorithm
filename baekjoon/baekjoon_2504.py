delimeter = input()
stack = []
flag = False
def isNumber(f) :
    try :
        float(f)
        return True
    except ValueError :
        return False

def top() :
    if len(stack) == 0 :
        return -1
    return stack[-1]

for c in delimeter :
    if c == '(' or c == '[' :
        stack.append(c)
    else :
        if len(stack) == 0 or isNumber(stack[0]):
            flag = True
            break
        if c == ')' :
            if isNumber(top()) : # 숫자
                # 한번 더 검사
                if stack[-2] == '[' :
                    flag = True
                    break
                tmp = top()*2
                stack.pop()
                stack.pop()
                if top() is not -1 and isNumber(top()) :
                    tmp2 = top()
                    stack.pop()
                    stack.append(tmp + tmp2)
                else :
                    stack.append(tmp)
            if top() == '(' :
                stack.pop()
                stack.append(2)
            if top() == '[' :
                flag = True
                break
        if c == ']' :
            if isNumber(top()) : # 숫자
                # 한번 더 검사
                if stack[-2] == '(' :
                    flag = True
                    break
                tmp = top()*3
                stack.pop()
                stack.pop()
                if top() is not -1 and isNumber(top()) :
                    tmp2 = top()
                    stack.pop()
                    stack.append(tmp + tmp2)
                else :
                    stack.append(tmp)
            if top() == '(' :
                flag = True
                break
            if top() == '[' :
                stack.pop()
                stack.append(3)
    print(stack)
if flag or len(stack) > 1 :
    print(0)
else :
    print(stack[0])