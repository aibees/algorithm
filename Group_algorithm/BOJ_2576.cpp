#include <iostream>

using namespace std;

int main(void) {
	int input, sum = 0, odd_min = 101;
	for(int i = 0; i < 7; i++) {	
		cin >> input;
		
		if(input % 2 == 1) {
			sum += input;
			if(odd_min > input) {
				odd_min = input;
			}
		}
	}
	
	if(sum == 0) {
		cout << -1;
		return 0;
	}
	else {
		cout << sum << '\n' << odd_min << '\n';
	}
	return 0;
}
