import java.util.*;

public class baekjoon_14503 {
   
   static int[][] map;
   static boolean[][] check;
   
   static int[] ROW = {0, 1, 0, -1};
   static int[] COL = {-1, 0, 1, 0};
   static robot r;
   
   static boolean isOk(int d) {//x = 세로, y = 가로
      boolean result = false;
      if(d ==3)
         result = check[r.x][r.y-1];
      else if(d ==2)
         result = check[r.x+1][r.y];
      else if(d ==1)
         result = check[r.x][r.y+1];
      else if(d ==0)
         result = check[r.x-1][r.y];
      return result;
   }
   
   static void Go(int d) {
      d = d % 4;
      if(d ==3)
         r.y--;
      else if(d ==2)
         r.x++;
      else if(d ==1)
         r.y++;
      else if(d ==0)
         r.x--;
      return;   
   }
   
   static void process() {
      int cnt = 0;
      boolean back = false;
      check[r.x][r.y] = false;
      cnt++;
      while(true) {
         //1. 현재 위치 청소
         //2. 왼쪽부터 좌표 확인
            //청소 안되어 있다면 회전하고 전진
            //공간 없다면 다른 방향으로 확인
            //4방향 모두 false라면 1칸 후진
            //모두 false이면서 반대방향이 1이라면 종료
    	 int blockingcnt = 0;
         while(true) {
            
            System.out.println(r.x + " " + r.y + " AND DIRECTION IS : " + r.getDirection());
            r.directChange();
            if(isOk(r.getDirection())) {
               break;
            }
            blockingcnt++;
            if(blockingcnt == 4) {// 전진할 공간 없으니 후진 또는 종료
               blockingcnt = 0;
               if(map[r.x + COL[(r.getDirection()+2)%4]][r.y + ROW[(r.getDirection()+2)%4]] == 1) { //후진할 곳이 벽일 경우
                  r.power = false;
                  break;
               }
               else { //벽이 아닐 경우
                  back = true;
                  break;
               }
            }
         }
         if(!r.power)
            break;
         
         if(back) {
            Go(r.getDirection()+2);
            if(check[r.x][r.y])
            	cnt++;
            check[r.x][r.y] = false;
            back = false;
         }
         else {
        	 Go(r.getDirection());
        	 check[r.x][r.y] = false;
        	 cnt++;
         }
      }
      System.out.println(cnt);
   }
   
   @SuppressWarnings("resource")
public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      int row, col, sero, garo, d;
      row = sc.nextInt();   col = sc.nextInt();
      sero = sc.nextInt();   garo = sc.nextInt();
      d = sc.nextInt();
      map = new int[row][col];
      check = new boolean[row][col];
      for(int i = 0; i < row; i++) {
         for(int j = 0; j < col; j++) {
            map[i][j] = sc.nextInt();
            if(map[i][j] == 0) {
               check[i][j] = true;
            }
            else check[i][j] = false;
         }
      }
      r = new robot(sero, garo, d);
      process();
   }
}

class robot {
   int x, y, direction;
   boolean power;
   //0 북, 1 동, 2 남, 3 서
   robot(int x, int y, int direction) {
      this.x = x;
      this.y = y;
      this.direction = direction;
      this.power = true;
   }
   
   int getDirection() {
      return direction;
   }
   
   boolean isPower() {
      return power;
   }
   
   void directChange() {
      if(direction == 0)
         direction = 3;
      else
         direction--;
   }
}