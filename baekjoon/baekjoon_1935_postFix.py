from math import floor

n = int(input())
op = input()
stack = []
res = ''
dic = {}
for i in range(n) :
    dic[chr(i+65)] = int(input())

for token in op :
    if ord(token) > 64 and ord(token) < 91 :
        stack.append(dic[token])
    else :
        res = 0
        b = stack.pop()
        a = stack.pop()
        if token == '*' :
            res = a*b
        elif token == '/' :
            res = a/b
        elif token == '+' :
            res = a+b
        elif token == '-' :
            res = a-b
        stack.append(res)
print(format(stack[0], ".2f"))