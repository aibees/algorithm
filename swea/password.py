T = int(input())

for test_case in range(1, T+1) :
    n, k = map(int, input().split(" "))
    gap = n // 4
    txt = input()
    txt = list(txt[::1])
    result_set = set()

    for j in range(gap) : # gap 만큼 돌려서 모든 수 구하기
        idx = 0
        
        while idx < len(txt) :
            if "".join(txt[idx:idx+gap]) not in result_set :
                result_set.add("".join(txt[idx:idx+gap]))
            idx += gap
        shift = txt.pop(0)
        txt.append(shift)
        
    li = []
    for num in list(result_set) :
        li.append(int(num, 16))
        
    li = sorted(li, reverse=True)
    answer = "#" + str(test_case) + " " + str(li[k-1])
    print(answer)