# ascii 'A' = 65
L = input();M = ""
for i in L :
    tmp = (ord(i) - 3)
    if tmp < 65 :
        tmp += 26
    M += chr(tmp)
print(M)