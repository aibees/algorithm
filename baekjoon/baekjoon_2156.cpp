#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n = 0;
vector<int> wine;
vector<int> d;
int main(void) {
	cin >> n;
	wine.resize(n+1);
	d.reserve(n+1);d[0] = 0;
	for(int i = 1; i <= n; i++) {
		int tmp = 0;
		cin >> tmp;
		wine[i] = tmp;
	}
	d[1] = wine[1];
	if(n == 1) {
		cout << d[n] << '\n';
		return 0;
	}
	d[2] = wine[1] + wine[2];
	for(int i = 3; i <= n; i++) {
		d[i] = max(d[i-1], max(d[i-2] + wine[i], d[i-3]+wine[i-1]+wine[i]));
	}
	cout << d[n] << '\n';
	return 0;
}