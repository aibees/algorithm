#include <iostream>

using namespace std;

int main(void) {
	
	int n = 0;
	cin >> n;
	
	for(int i = 1; i <= n; i++) {
		int output = i*2 - 1;
		int space = n - i;
		
		// space
		for(int j = 0; j < space; j++) {
			cout << ' ';
		}
		
		//star
		for(int j = 0; j < output; j++) {
			cout << '*';
		}
		cout << '\n';
	}
	
	return 0;
}
