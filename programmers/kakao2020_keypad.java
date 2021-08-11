import java.util.*;
import java.util.stream.IntStream;

class Solution {
    private char[][] pad = { // 키패드 선언
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'},
        {'*','0','#'}
    };
    private Map<Character, Position> mapping = new HashMap<Character, Position>(); // 키패드 별 포지션 매핑

    // 각 손의 전담 키패드
    private int[] lLine = {1,4,7};
    private int[] rLine = {3,6,9};

    private String hand; // 왼손잡이/오른손잡이

    public String solution(int[] numbers, String hand) {
        String answer = "";

        this.hand = hand;
        init(); // hashmap 초기화

        // 초기 오른손/왼손 위치
        Position l = mapping.get('*');
        Position r = mapping.get('#');

        for(int i : numbers) { // loop 시작
            char c = (char)(i + '0');
            Position p = mapping.get(c);

            if(IntStream.of(lLine).anyMatch(x->x == i)) {
                // 왼손 직행
                answer += 'L';
                l = p;
            } else if(IntStream.of(rLine).anyMatch(x->x == i)) {
                //오른손 직행
                answer += 'R';
                r = p;
            } else {
                // 거리계산 시작 (단순 유클리드 거리 계산으로도 충분)
                int lDist = Math.abs(p.row - l.row) + Math.abs(p.col - l.col);
                int rDist = Math.abs(p.row - r.row) + Math.abs(p.col - r.col);

                if(lDist < rDist) { answer += 'L'; l = p; }
                else if(lDist > rDist) { answer += 'R'; r= p; }
                else {
                    if("right".equals(this.hand)) { answer += 'R'; r= p; }
                    else if("left".equals(this.hand)) { answer += 'L'; l = p; }
                }
            }
        }
        return answer;
    }

    private void init() {
        this.mapping.put('1', new Position(0, 0));
        this.mapping.put('2', new Position(0, 1));
        this.mapping.put('3', new Position(0, 2));
        this.mapping.put('4', new Position(1, 0));
        this.mapping.put('5', new Position(1, 1));
        this.mapping.put('6', new Position(1, 2));
        this.mapping.put('7', new Position(2, 0));
        this.mapping.put('8', new Position(2, 1));
        this.mapping.put('9', new Position(2, 2));
        this.mapping.put('*', new Position(3, 0));
        this.mapping.put('0', new Position(3, 1));
        this.mapping.put('#', new Position(3, 2));
    }
}

class Position { // 손 및 키패드 위치관리를 위한 클래스 생성
    public Position(int row, int col) {
        this.row = row;
        this.col = col;
    }

    public int row;
    public int col;

    public String toString() {
        return this.row + ", " + this.col;
    }
}
