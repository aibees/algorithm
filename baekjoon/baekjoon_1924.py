calendar = {}
calendar[0] = 31
calendar[1] = 28
calendar[2] = 31
calendar[3] = 30
calendar[4] = 31
calendar[5] = 30
calendar[6] = 31
calendar[7] = 31
calendar[8] = 30
calendar[9] = 31
calendar[10] = 30
calendar[11] = 31

days = {}
days[0] = 'MON'
days[1] = 'TUE'
days[2] = 'WED'
days[3] = 'THU'
days[4] = 'FRI'
days[5] = 'SAT'
days[6] = 'SUN'
d = 0
a, b = map(int, input().split( ))
for i in range(a-1) :
    if calendar[i] == 28 :
        continue
    elif calendar[i] == 31 :
        d += 3
    else :
        d += 2
    d %= 7
print(d)
for i in range(1, b) :
    d += 1
    if d == 7 :
        d = 0
print(days[d])