import java.util.*;

class MissingInteger {
    public static void main(String[] args) {
        MissingInteger OIA = new MissingInteger();
        OIA.mainProc();
    }

    public void mainProc() {
        Solution sol = new Solution();
        int ret = sol.solution(A);
        System.out.println(ret);
    }

    // you can write to stdout for debugging purposes, e.g.
    // System.out.println("this is a debug message");

    class Solution {
        public int solution(int[] A) {
            int num = 1;
            HashSet<Integer> h = new HashSet<Integer>();
    
            for (int i = 0 ; i < A.length; i++) {
                h.add(A[i]);                     
            }
    
             while (h.contains(num)) {
                    num++;
                }
    
            return num;
        }
    }
}