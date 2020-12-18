class Solution {
    public String convert(String s, int numRows) {
        if(numRows == 1) {
            return s;
        }
        
        String answer = "";
        boolean bp = false;
        
        StringBuilder sb = new StringBuilder();
        
        char[][] ch = new char[numRows+1][1000];
        int row = 0;
        int line = 0;
        
        for(int i = 0; i < s.length();) {
            // down
            for(int j = 0; j < numRows; j++) {
                ch[row][line] = s.charAt(i);
                row++;
                i++;
                if(i == s.length()) {
                    bp = true;
                    break;
                }
            }
            if(bp) { break; }
            
            row--;
            //up
            for(int k = 0; k < numRows-2; k++) {
                line++;
                row--;
                ch[row][line] = s.charAt(i);
                i++;
                
                if(i == s.length()) {
                    bp = true;
                    break;
                }
            }
            if(bp) { break; }
            
            line++;
            row--;
        }
        
        for(int i = 0; i < numRows+1; i++) {
            for(int j = 0; j< line+1; j++) {
                if(ch[i][j] != '\u0000') {
                    answer += ch[i][j];
                }
            }
        }
        
        return answer;
    }
}