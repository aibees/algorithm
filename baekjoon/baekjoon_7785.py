li = []
for i in range(int(input())) :
    n = input().split(' ')
    if n[1] == 'enter' :
        li.append(n[0])
    elif n[1] == 'leave' and n[0] in li != ValueError:
        li.remove(n[0])
print(li)
