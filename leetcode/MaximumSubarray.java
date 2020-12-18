class Solution {
    public int maxSubArray(int[] nums) {
        int answer = nums[0];
        int minusMax = nums[0];
        if(minusMax > 0) {
            minusMax = -2147483647;
        }
        int[] sums = new int[nums.length];
        
        if(nums[0] < 0) {
            sums[0] = 0;
        } else {
            sums[0] = nums[0];
        }
        
        for(int i = 1; i < nums.length; i++) {
            // minux max
            if(nums[i] <= 0 && minusMax < nums[i]) {
                minusMax = nums[i];
            }
            
            int tmp = sums[i-1] + nums[i];
            if(tmp < 0) {
                tmp = 0;
            }
            sums[i] = tmp;
            if(answer < sums[i]) {
                answer = sums[i];
            }
        }
        if(answer < sums[nums.length-1]) {
            answer = sums[nums.length-1];
        }
        
        if(answer == 0) {
            answer = minusMax;
        }
        
        return answer;
    }
}