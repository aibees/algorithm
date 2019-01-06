# baekjoon algorithm coding test
# written by aibees1129@naver.com

'''상근이는 초등학교에 다닐 때, 방학 숙제를 남들보다 먼저 미리 하고 남은 기간을 놀았다. 방학 숙제는 수학과 국어 문제 풀기이다.

방학은 총 L일이다. 수학은 총 B페이지, 국어는 총 A페이지를 풀어야 한다. 상근이는 하루에 국어를 최대 C페이지, 수학을 최대 D페이지 풀 수 있다.

상근이가 겨울 방학동안 숙제를 하지 않고 놀 수 있는 최대 날의 수를 구하는 프로그램을 작성하시오.
'''
N = [] #L, A, B, C, D
i = 0
while i < 5:
    j = int(input())
    N.append(j)
    i = i + 1

a = N[1] // N[3]
if N[1] % N[3] != 0 :
    a = a + 1

b = N[2] // N[4]
if N[2] % N[4] != 0 :
    b = b + 1

if a <= b :
    print(N[0] - b)
else :
    print(N[0] - a)