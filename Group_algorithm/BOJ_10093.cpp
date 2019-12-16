#include <iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	
	unsigned long long int N, M, tmp;
	cin >> N >> M;
	
	if(N > M) {
		tmp = N;
		N = M;
		M = tmp;
	}
	
	if(N != M)
		cout << M - N - 1 << '\n';
	else {
		cout << 0 << '\n';
		return 0;
	}
	
	while(N < M-1) {
		N++;
		cout << N << ' ';
	}
	
	return 0;
}
