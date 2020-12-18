package algorithm;

public class HeapSort {

	public static void main(String[] args) {
		HeapSort hs = new HeapSort();
		hs.mainProc();
	}
	
	private void mainProc() {
		int[] ex = {6, 4, 7, 1, 8, 2, 5, 3};
		int[] ret = solution(8, ex);
		
		for(int i = 0; i < ret.length; i++) {
			System.out.print(ret[i] + " ");
		}
	}
	
	private int[] solution(int num, int[] list) {
		int[] answer = null;
		
		heap(num, list);
		
		for(int i = num-1; i >= 0; i--) {
			// root(첫 번째 원소)값을 마지막 node로 이동
			int tmp = list[i];
			list[i] = list[0];
			list[0] = tmp;
			
			heap(i, list);
			
			for(int j = 0; j < list.length; j++) {
				System.out.print(list[j] + " ");
			}
			System.out.println("\n");
		}
		
		answer = list;
		
		return answer;
	}
	
	private void heap(int num, int[] list) {
		for(int i = 1; i < num; i++) { // 앞에서부터 하나씩 체크
			int child = i;
			while(child > 0) { //child가 0이 되면 (root가 되면) while 종료
				int root = (child - 1) / 2; // 부모node 찾은 뒤
				if(list[root] < list[child]) { // child가 parent보다 크면 swap
					int tmp = list[root];
					list[root] = list[child];
					list[child] = tmp;
				}
				child = root; // parent로 올라감
			}
		}
	}
}
