package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ_15655 {

	private static int[] num;
	private static int n, m;
	
	public static void process(int cnt, int start, String result, ArrayList<Integer> check) {
		if(cnt == m) {
			System.out.println(result);
			return;
		}
		else {
			for(int i = start; i < n; i++) {
				// System.out.println("cnt : " + cnt + ", i : " + i + ", result : " + result);
				if(check.contains(num[i])) {
					continue;
				}
				check.add(num[i]);
				process(cnt+1, i, result + num[i] + " ", check);
				check.remove(check.indexOf(num[i]));
				
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
		process(0, 0, "", new ArrayList<Integer>());
	}

}
