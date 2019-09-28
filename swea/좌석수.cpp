#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool desc(int a, int b) {
	return a > b;
}

int main(int argc, char** argv) {
	int test_case;
	int T;
	
	cin >> T;
	
	for(test_case = 1; test_case <= T; ++test_case) {
		// ##############
		int num = 0, x = 0, cnt = 0;
		cin >> num;
		cnt += num;
		vector<int> tmp; tmp.reserve(num);
		for(int i = 0; i < num; i++) {
			cin >> x;
			tmp.push_back(x);
		}
		sort(tmp.begin(), tmp.end(), desc);
		
		cnt += tmp[0];
		for(int j = 0; j < tmp.size(); j++) {
			cnt += tmp[j];
		}
		
		cout << "#" << test_case << " " << cnt << '\n';
		// ##############
	}
	
	return 0;
}
