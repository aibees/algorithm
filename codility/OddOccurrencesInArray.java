import java.util.*;

class OddOccurencesInArray {
    public static void main(String[] args) {
        OddOccurencesInArray OIA = new OddOccurencesInArray();
        OIA.mainProc();
    }

    public void mainProc() {
        Solution sol = new Solution();

        int ret = sol.solution(A);
    }

    // you can write to stdout for debugging purposes, e.g.
    // System.out.println("this is a debug message");

    class Solution {
        public int solution(int[] A) {
            HashMap<Integer, Integer> B = new HashMap<Integer, Integer>();

            for(int a : A) {
                if(B.containsKey(a)) {
                    // 들어있음
                    B.remove(a);
                }
                else {
                    // 들어있지 않음
                    B.put(a, 1);
                }
            }
            // return keyset
            Set<Integer> keys = B.keySet();
            Iterator<Integer> iter = keys.iterator();
            int answer = iter.next();

            return answer;
        }
    }
}