#include <iostream>

using namespace std;

int main(void) {
	
	int n = 0;
	cin >> n;
	
	for(int i = 0; i < n-1; i++) {
		int output = (n - i)*2 - 1;
		int space = i;
		
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
	
	for(int i = 0; i < n-1; i++) {
		cout << ' ';
	}
	cout << "*\n";
	
	for(int i = n-2; i >= 0; i--) {
		int output = (n - i)*2 - 1;
		int space = i;
		
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
