li = {}
for i in range(int(input())) :
    n = input().split(' ')
    if n[1] == 'enter' :
        li[n[0]] = True
    elif n[1] == 'leave' and n[0] in li.keys() != ValueError:
        del(li[n[0]])
a = list(li.keys())
a.sort(reverse = True)
for i in a :
    print(i)
