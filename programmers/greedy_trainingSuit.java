import java.util.*;

class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int[] student = new int[n+1];
        Arrays.fill(student, 1);

        for(int r : reserve) { student[r] = 2; }
        for(int l : lost) { student[l]--; }

        for(int i = 1; i < student.length; i++) {
            if(0 == student[i]) {
                // 앞에 있는 애 보고
                if(i-1 > 0 && student[i-1] > 1) {
                    student[i]++;
                    student[i-1]--;
                }
                // 뒤에 있는 애 보고
                else if(i+1 < student.length && student[i+1] > 1) {
                    student[i]++;
                    student[i+1]--;
                }


                // for(int s : student)
                //     System.out.print(s + " ");
                // System.out.println();
            }
        }

        int answer = 0;

        for(int s : student)
            if(s > 0) answer++;

        return answer-1;
    }
}
