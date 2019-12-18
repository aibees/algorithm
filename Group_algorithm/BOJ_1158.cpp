#include <iostream>
#include <deque>

using namespace std;

int answer[5001] = {0, };
deque<int> people;

int main(void) {
	int n, k, idx = 0;
	cin >> n >> k;
	
	for(int i = 1; i <= n; i++) {
		people.push_back(i);
	}
	
	while(!people.empty()) {
		int target = -1;
		for(int t = 0; t < k-1; t++) {
			people.push_back(people.front());
			people.pop_front();
		}
		target = people.front();
		people.pop_front();
		
		answer[idx] = target;
		idx++;
	}
	
	cout << '<';
	for(int i = 0; i < n-1; i++) {
		cout << answer[i] << ", ";
	}
	cout << answer[n-1] << ">\n";
	return 0;
}
