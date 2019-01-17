# baekjoon algorithm coding test
# written by aibees1129@naver.com

""" S = input();cnt = 0
alphabet = [-1 for i in range(26)]
for i in S :
    if alphabet[ord(i) - 97] == -1 :
        alphabet[ord(i) - 97] = cnt
    cnt += 1
result = ""
for i in alphabet :
    result += str(i)
    result += " "
print(result) """

print(*map(input().find,map(chr,range(97,123))))

# asterisk = unpacking