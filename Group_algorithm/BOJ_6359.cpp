#include <iostream>

using namespace std;

int getFactor(int n) {
	int ret = 0;
	int i = -1;
	for(i = 1; i*i < n; i++) {
		if(n % i == 0) {
			ret += 2;
		}
	}
		
	if(i*i == n) {
		ret++;
	}
	
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T;	cin >> T;
	for(int test_case = 1; test_case <= T; test_case++) {
		int n, result = 1;	cin >> n;
		for(int i = 2; i <= n; i++) {
			int factor = getFactor(i);
			//cout << "n : " << n << ", i : " << i << ", factor : " << factor << '\n';
			if(factor % 2 == 1) {
				result++;
			}
		}
		cout << result << '\n';
	}
	
	return 0;
}
