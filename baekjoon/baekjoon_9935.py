s = input(); ex = input()
cnt = 0
for i in s :
    if i == ex[len(ex)-1] :
        cnt+=1
for i in range(cnt) :
    tmp = s.split(ex)
    s = "".join(tmp);
print(s)