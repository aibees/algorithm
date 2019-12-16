def solution(jobs) :
    if len(jobs) is 1 :
        print(jobs[0])
        return jobs[0][1] - jobs[0][0]
    s_sum = 0; time = 0
    timeJob = sorted(jobs, key = lambda x : (x[0], x[1]))
    cnt = len(jobs)
    tmp = [timeJob[0]]
    del timeJob[0]
    time += tmp[0][0]
    while len(timeJob) > 0 :
        while len(tmp) > 0 :
            # job processing
            job = tmp[0]; del tmp[0]
            time += job[1]
            s_sum += (time - job[0])
            
            # select next job list
            remove_ = []
            for i in range(len(timeJob)) :
                item = timeJob[i]
                if time > item[0] :
                    tmp.append(timeJob[i])
                    remove_.append(item)
                else :
                    break
            
            # exist next job
            if len(remove_) > 0 :
                for r_item in remove_ :
                    timeJob.remove(r_item)
            # no next job
            elif len(remove_) is 0 and len(tmp) is 0 and len(timeJob) > 0 :
                tmp_job = timeJob[0]
                tmp.append(tmp_job); timeJob.remove(tmp_job)
                time = tmp_job[0]
            # sort tmp by job scale
            tmp = sorted(tmp, key = lambda x : x[1])

    return s_sum//cnt
    

print(solution([[1, 3]]))