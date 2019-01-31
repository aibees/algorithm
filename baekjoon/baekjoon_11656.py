""" baekjoon algorithm 11656
    written by aibees1129   """

""" list = []
word = input()

for i in range(len(word)) :
    list.append(word[i:])

for i in sorted(list) :
    print(i) """

# short coding
word = input();[*map(print, sorted(word[i:] for i in range(len(word))))]