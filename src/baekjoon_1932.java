import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class baekjoon_1932 {
	public static void main(String[] args) {

		List<List<Integer>> layer = new ArrayList<List<Integer>>();
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		try {
			int n = Integer.parseInt(br.readLine().toString());
			
			for(int i = 0; i < n; i++) {
				String[] row = br.readLine().split(" ");
				List<Integer> tmp = new ArrayList<Integer>();
				
				for(int idx = 0; idx < row.length; idx++) {
					tmp.add(Integer.parseInt(row[idx]));
				}
				
				layer.add(tmp);
			}
			
			br.close();
			
			for(int i = 1; i < n; i++) {
				List<Integer> now = layer.get(i-1);
				List<Integer> next = layer.get(i);
				
				for(int j = 0; j < next.size(); j++) {
					int a = -1, b = -1;
					if(j-1 >= 0) {
						a = now.get(j-1);
					}
					if(j < now.size()) {
						b = now.get(j);
					}
					
					
				}
			}
			
		} catch (NumberFormatException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
