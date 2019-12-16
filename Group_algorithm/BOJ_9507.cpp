#include <iostream>

using namespace std;

unsigned long long int arr[68] = {0, };
int Max = 3;

void getMore(int n) {
	Max++;
	for(int i = Max; i <= n; i++) {
		arr[i] = (arr[i-1] + arr[i-2] + arr[i-3] + arr[i-4]);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// arr init
	arr[0] = arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	
	int T;	cin >> T;
	for(int test_case = 1; test_case <= T; test_case++) {
		int n = 0;	cin >> n;
		
		if(Max < n) {
			getMore(n);
			Max = n;
		}
		cout << arr[n] << '\n';
	}
	
	return 0;
}
