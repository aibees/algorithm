import java.util.*;

class Solution {
    private Map<String, Integer> m = new HashMap<String, Integer>();
    
    public int solution(String s) {
        String answer = "";
        init();
        String tmp = "";
        for(int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if(c >= '0' && c <= '9') { answer += c; }
            else {
                tmp += c;
                int num = getNumber(tmp);
                if(-1 == num) {
                    continue;
                } else {
                    answer += (char)('0' + num);
                    tmp = "";
                }
            }
        }
        
        return Integer.parseInt(answer);
    }
    
    private int getNumber(String number) {
        if(m.containsKey(number)) {
            return m.get(number);
        } else { return -1; }
    }
    
    private void init() {
        m.put("zero",  0);
        m.put("one",   1);
        m.put("two",   2);
        m.put("three", 3);
        m.put("four",  4);
        m.put("five",  5);
        m.put("six",   6);
        m.put("seven", 7);
        m.put("eight", 8);
        m.put("nine",  9);
    }
}

////////////////////////////

class Solution {
    public int solution(String s) {
        int answer = 0;
        StringBuilder sb = new StringBuilder("");
        int len = s.length();
        String[] digits = {"0","1","2","3","4","5","6","7","8","9"};
        String[] alphabets = {"zero","one","two","three","four","five","six","seven","eight","nine"};

        for(int i=0; i<10; i++){
            s = s.replaceAll(alphabets[i],digits[i]);
        }

        return Integer.parseInt(s);
    }
}
