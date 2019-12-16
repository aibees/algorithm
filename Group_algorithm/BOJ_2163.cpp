#include <iostream>

using namespace std;

int main(void) {
	
	int result = 0, n, m;
	cin >> n >> m;
	
	result += (n-1);
	result += n*(m-1);
	
	cout << result << '\n';
	return 0;
}
