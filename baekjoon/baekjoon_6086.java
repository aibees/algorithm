import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class baekjoon_2188 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer tk = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(tk.nextToken());
		int m = Integer.parseInt(tk.nextToken());
		
	    int size = n + m + 2;
	    
	    int[][] capacity = new int[size][size];
	    int[][] flow = new int[size][size];
	    
	    for(int i = 0; i < n; i++) {
	    	capacity[0][i] = 1;
	    }
	    for(int i = n-1; i > -1; i--) {
	    	
	    }
	}
}
