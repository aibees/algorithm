import java.util.*;
import java.io.*;

class baekjoon_11559 {
	static char[][] puyo = new char[12][6];
	static boolean[][] check;
	static Queue<node> q = new LinkedList<>();
	static ArrayList<node> list = new ArrayList<>();
	static int[] UD = {0, 0, 1, -1};
	static int[] RL = {1, -1, 0, 0};
	
	static void process() {
		int result = 0;
		while(true) {
			boolean flag = false;
			down();
			for(int i = 0; i < 12; i++) {
				for(int j = 0; j < 6; j++) {
					if(puyo[i][j] == '.')
						continue;
					
					check = new boolean[12][6];
					check[i][j] = true;
					int blockcnt = 0;
					q.add(new node(i,j));
					
					while(!q.isEmpty()) {
						node current = q.poll();
						blockcnt++;
						list.add(current);
						for(int k = 0; k <4; k++) {
							int dx = current.x + UD[k];
							int dy = current.y + RL[k];
							
							if(!rangecheck(dx, dy) || check[dx][dy] == true || puyo[dx][dy] != puyo[current.x][current.y])
								continue;
							check[dx][dy] = true;
							q.add(new node(dx, dy));
						}
					}
					if(blockcnt > 3) {
						for(node n : list) {
							puyo[n.x][n.y] = '.';
						}
						flag = true;
					}
					list.clear();
				}
			}
			if(!flag)
				break;
			result++;
		}
		System.out.println(result);
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String a = "";
		for(int i = 0; i < 12; i++) {
			a = sc.next();
			for(int j = 0; j < 6; j++) {
				puyo[i][j] = a.charAt(j);
			}
		}
		
		process();
	}
	
	static void down() {
		for(int i = 11; i >= 0; i--) {
			for(int j = 0; j < 6; j++) {
				if(puyo[i][j] == '.')	continue;
				
				int floor = i;
				char tmp = puyo[i][j];
				puyo[i][j] = '.';
				while(true) {
					if(!rangecheck(floor+1, j) || puyo[floor+1][j] != '.')
						break;
					floor++;
				}
				puyo[floor][j] = tmp;
			}
		}
	}
	
	static boolean rangecheck(int x, int y) {
		if(x > 11 || x < 0 || y > 5 || y < 0)
			return false;
		else
			return true;
	}
}
 
class node {
    int x;
    int y;
    
    node() {
    	this.x = 0;
    	this.y = 0;
    }
    
    node (int x, int y) {
        this.x = x;
        this.y = y;
    }
}