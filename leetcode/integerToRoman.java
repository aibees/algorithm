class Solution {
    HashMap<Integer, String> hm = new HashMap<Integer, String>();
    
    private void init() {
        hm.put(1, "I");
        hm.put(4, "IV");
        hm.put(5, "V");
        hm.put(9, "IX");
        hm.put(10, "X");
        hm.put(40, "XL");
        hm.put(50, "L");
        hm.put(90, "XC");
        hm.put(100, "C");
        hm.put(400, "CD");
        hm.put(500, "D");
        hm.put(900, "CM");
        hm.put(1000, "M");
    }
    
    public String intToRoman(int num) {
        init();
        
        String answer = "";
        int divide = 1000;
        
        while(num > 0) {
            int a = num / divide;
            int b = num % divide;
            
            if(a == 0) {
                num = b;
                divide = divide / 10;
                continue;
            }
            
            // map에서 뽑아오기
            String roman = "";
            if(divide < 1000 && a == 4 || a == 9) {
                roman = hm.get(a * divide);
            }
            else {
                if(a >= 5) {
                    roman += hm.get(divide * 5);
                    a -= 5;
                }
                if(a > 0) {
                    String r = hm.get(divide);
                    for(int i = 0; i < a; i++) {
                        roman += r;
                    }
                }
            }
            answer = answer + roman;
            num = b;
            divide = divide / 10;
        }
        return answer;
    }
}