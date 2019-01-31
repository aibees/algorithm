//baekjoon algorithm 1463
//written by aibees1129

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int A[1000001];

void process(int n) {
	A[1] = 0;
	for(int i = 2; i < n+1; i++) {
		A[i] = A[i-1] + 1;
		if(i % 2 == 0) {
			A[i] = min(A[i], A[i/2] + 1);
		}
		if(i % 3 == 0) {
			A[i] = min(A[i], A[i/3] + 1);
		}
	}
	cout << A[n] << '\n';
}

int main(void) {
	int n = 0;
	cin >> n;
	memset(A, 0, sizeof(int)*(n+1));
	process(n);
	return 0;
}