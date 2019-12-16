#include <iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	
	int n = 0;
	cin >> n;
	
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < i; j++) {
			cout << '*';
		}
		cout << '\n';
	}
	return 0;
}
