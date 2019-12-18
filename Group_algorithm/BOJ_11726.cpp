#include <iostream>
#include <vector>

using namespace std;

unsigned long long int tile[1001] = {0, };

int main(void) {
	int n = 0;
	cin >> n;
	
	tile[0] = 1;
	tile[1] = 1;
	tile[2] = 2;
	tile[3] = 3;
	
	if(n > 3) {
		for(int i = 4; i < n+1; i++) {
			tile[i] = (tile[i-1] + tile[i-2]) % 10007;
		}
	}
	
	cout << (tile[n] % 10007) << '\n';
	return 0;
}
