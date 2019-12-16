#include <iostream>

using namespace std;

int main(void) {	
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int n = 0;
	cin >> n;
	for(int i = n; i >= 0; i--) {
		int m = n - i;
		for(int k = 0; k < m; k++) {
			cout << ' ';
		}
		
		for(int j = 0; j < i; j++) {
			cout << '*';
		}
		cout << '\n';
	}
	
	return 0;
}
