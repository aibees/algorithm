package algorithm;

import java.util.*;
public class GenomicRangeQuery {
	public static void main(String[] args) {
		GenomicRangeQuery grq = new GenomicRangeQuery();
		grq.mainProc();
	}
	
	private void mainProc() {
		Solution sol = new Solution();
		int[] P = {0, 1, 1, 0};
		int[] Q = {0, 1, 2, 2};
		int[] answer = sol.solution("AGC", P, Q);
		
		for(int i : answer) {
			System.out.print(i + " ");
		}
		System.out.println();
	}
}


//you can also use imports, for example:

//you can write to stdout for debugging purposes, e.g.
//System.out.println("this is a debug message");

class Solution {
 public int[] solution(String S, int[] P, int[] Q) {
    int[] answer = new int[P.length];

    int[] A = new int[S.length()];
    int[] C = new int[S.length()];
    int[] G = new int[S.length()];

    for(int i = 0; i < S.length(); i++) {
        if(i > 0) {
            A[i] = A[i-1];
            C[i] = C[i-1];
            G[i] = G[i-1];
        }
        char tmp = S.charAt(i);
        if(tmp == 'A') {
            A[i]++;
        }
        else if(tmp == 'C') {
            C[i]++;
        }
        else if(tmp == 'G') {
            G[i]++;
        }
    }
    
    for(int i = 0; i < S.length(); i++) {
    	System.out.print(A[i] + " ");
    }
    System.out.println();
    for(int i = 0; i < S.length(); i++) {
    	System.out.print(C[i] + " ");
    }
    System.out.println();
    for(int i = 0; i < S.length(); i++) {
    	System.out.print(G[i] + " ");
    }
    System.out.println();

    for(int i = 0; i < P.length; i++) {
        if(A[P[i]] != A[Q[i]]) { // A가 최소
            answer[i] = 1;
        } else if(C[P[i]] != C[Q[i]]) {
            answer[i] = 2;
        } else if(G[P[i]] != G[Q[i]]) {
            answer[i] = 3;
        } else {
            answer[i] = 4;
        }
    }
    
    return answer;
 }
}
