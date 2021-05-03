import java.util.*;

class Solution {
    public int singleNumber(int[] nums) {
        int answer = -30001;
        Map<Integer,Boolean> check = new HashMap<Integer, Boolean>();
        
        for(int i : nums) {
            if(check.containsKey(i)) {
                // 있으면
                check.remove(i);
            } else {
                // 없으면
                check.put(i, true);
            }
        }
        
        Iterator<Integer> key = check.keySet().iterator();
        answer = key.next();
        
        return answer;
    }
}