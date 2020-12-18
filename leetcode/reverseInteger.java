/**
 *  자릿수마다 나누어서 Reverse하는방법은 너무 뻔해서...
 */

class Solution {
    public int reverse(int x) {
        int answer = -2147483648;
        String tmpAns = "";
        
        boolean minus = false;
        if(x < 0) minus = true;
        
        String num = Integer.toString(x);
        num = num.replace("-", "");
        
        for(int i = num.length()-1; i >= 0; i--) {
            tmpAns = tmpAns + num.charAt(i);
        }
        
        try {
            answer = Integer.parseInt(tmpAns);
            if(minus) {
                answer *= (-1);
            }
        } catch(Exception e) {
            answer = 0;
        }

        return answer;
    }
}