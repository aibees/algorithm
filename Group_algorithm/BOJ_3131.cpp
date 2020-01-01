#include <iostream>
#include <queue>

using namespace std;

priority_queue<long long int> pq;
int n;
long long int a, b, ob, yb, lower, upper;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> a >> b >> n;
	for(int i = 0; i < n-1; i++) {
		long long int tmp;
		cin >> tmp;
		pq.push(tmp);
	}
	
	bool flag = false;
	while(!pq.empty()) {
		if(!flag) {
			ob += pq.top();
		}
		else {
			yb += pq.top();
		}
		pq.pop();
		if(flag == true) { flag = false; }
		else { flag = true; }
	}
	
	lower = ob - yb - b;
	upper = ob - yb - a;
	
	cout << upper;
	
	return 0;
}
