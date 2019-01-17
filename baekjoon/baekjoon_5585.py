# baekjoon algorithm coding test
# written by aibees1129@naver.com
cnt = 0;coin = [500, 100, 50, 10, 5, 1];cost = 1000 - int(input())
for i in coin :
    cnt += cost // i
    cost = cost % i
print(cnt)