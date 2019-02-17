""" baekjoon algorithm 11656
    written by aibees1129   """

N = int(input())
s, e = input().split('*')

for i in range(N) :
    File = input()
    print("DA" if File[:len(s)] == s and File[(-1)*len(e):] == e and (len(s) + len(e) <= len(File)) else "NE")