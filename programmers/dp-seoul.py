def solution(K, travel):
    cache = [[0] * (len(travel)+1) for i in range(K+1)]
    for i in range(1, len(travel)+1) :
        Max = -1
        walkTime = travel[i-1][0]
        walkMoney = travel[i-1][1]
        rideTime = travel[i-1][2]
        rideMoney = travel[i-1][3]
        for j in range(K+1) :
            if j >= walkTime and cache[j-walkTime][i-1] is not -1 and (walkMoney + cache[j-walkTime][i-1] > Max) :
                Max = walkMoney + cache[j-walkTime][i-1]
            if j >= rideTime and cache[j-rideTime][i-1] is not -1 and (rideMoney + cache[j-rideTime][i-1] > Max) :
                Max = rideMoney + cache[j-rideTime][i-1]
            if Max is not -1 :
                cache[j][i] = Max
            
    return cache[K][len(travel)]

print(solution(1650, [[500, 200, 200, 100], [800, 370, 300, 120], [700, 250, 300, 90]]))
print(solution(3000, [[1000, 2000, 300, 700], [1100, 1900, 400, 900], [900, 1800, 400, 700], [1200, 2300, 500, 1200]]))