class Solution {
    public boolean isPalindrome(int x) {
        boolean answer = false;
        
        String num = Integer.toString(x);
        int cnt = num.length();
        int start = 0;
        int last = cnt-1;
        
        boolean tmp = true;
        while((last - start) >= 1) {

            if(num.charAt(start) != num.charAt(last)) {
                tmp = false;
            }
            if(!tmp) {
                break;
            }
            start++;
            last--;
        }
        answer = tmp;
        
        return answer;
    }
}