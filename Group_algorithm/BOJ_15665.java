package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ_15665 {

	private static int[] num;
	private static int n, m;
	private static Map<String, Boolean> result_check = new HashMap<String, Boolean>();
	
	public static void process(int cnt, String result) {
		if(cnt == m) {
			if(result_check.get(result) == null) {
				System.out.println(result);
				result_check.put(result, true);
			}
			return;
		}
		else {
			for(int i = 0; i < n; i++) {
				// System.out.println("cnt : " + cnt + ", i : " + i + ", result : " + result);
				
				process(cnt+1, result + num[i] + " ");
			}
		}
		return;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		num = new int[n];
		
		st = new StringTokenizer(br.readLine());
		for(int i = 1; i <= n; i++) {
			num[i-1] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(num);
		process(0, "");
	}


}
