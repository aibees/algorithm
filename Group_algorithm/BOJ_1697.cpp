#include <iostream>

using namespace std;

int answer = 100000;

void process(int start, int end, int cnt) {
	if(start == end) {
		if(answer > cnt) {
			answer = cnt;
			return;
		}
	}
	else {
		cout << "start : " << start << ", end : " << end << ", cnt : " << cnt << '\n';
		if(start < 0) {
			return;
		}
		else {
			process(start+1, end, cnt+1);
			process(start-1, end, cnt+1);
			process(start*2, end, cnt+1);
		}
	}
	
	
}

int main(void) {
	int N, K;
	cin >> N >> K;
	
	process(N, K, 0);
	
	cout << answer << '\n';
	return 0;
}
