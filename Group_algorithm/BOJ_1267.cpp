#include <iostream>

using namespace std;

int main(void) {
	int n = 0;
	cin >> n;
	int Y = 0, M = 0;
	for(int i = 0; i < n; i++) {
		int tmp = 0, y = 0, m = 0;
		cin >> tmp;
		
		// Y
		y = tmp / 30 + 1;
		
		Y += y*10;
		
		// M
		m = tmp / 60 + 1;
		
		M += m*15;
	}
	//cout << "Y : " << Y << " , M : " << M << '\n';
	if(Y > M) {
		cout << "M " << M ;
	}
	else if(Y < M) {
		cout << "Y " << Y;
	}
	else {
		cout << "Y M " << Y;
	}
	
	return 0;
}
