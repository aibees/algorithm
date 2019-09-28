import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class baekjoon_1937 {
	// 위 왼쪽 아래 오른쪽
	final static int[] x = {0, -1, 0, 1};
	final static int[] y = {-1, 0, 1, 0};
	
	static int N;
	static int[][] maps, memorize;
	
	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(bf.readLine().trim());
		memorize = new int[N][N];
		maps = new int[N][N];
		
		for(int i = 0; i < N; i++) {
			String[] tmp = bf.readLine().trim().split(" ");
			for(int j = 0; j < tmp.length; j++) {
				maps[i][j] = Integer.parseInt(tmp[j]);
				memorize[i][j] = -1;
			}
		}
		
		
		int result = 0;
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				//System.out.println("======== start =========");
				result = Math.max(result,  dfs(i, j));
			}
		}
		
		System.out.println(result);
	}
	
	private static int dfs(int i, int j) {
		// System.out.println("current : " + i + ", " + j + " -> value : " + maps[i][j]);
		if(memorize[i][j] != -1)
			return memorize[i][j]; // -1이 아닌 지점은 해당 지점부터 어디까지 갈지 뻔하기 때문에 여기서 stop
		
		int cnt = 1;
		for(int d = 0; d < 4; d++){
			int nextX = i + x[d];
			int nextY = j + y[d];
		    if((nextX >=0 && nextX < N) && (nextY >= 0 && nextY < N)){
		    	if(maps[nextX][nextY] > maps[i][j]){
		    		cnt = Math.max(cnt, dfs(nextX, nextY)+1);
		    		// System.out.println("\tNext : " + nextX + ", " + nextY + " -> cnt : " + cnt);
		    		memorize[i][j] = cnt; //재귀에서 돌아온 뒤 가장 큰 cnt 값을 memorize 배열에 저장
		    	}
		    }
		}
		return cnt;
	}

}