#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> num_list, ex;

int search(int target) {
	int first = 0, last = num_list.size()-1, mid = 0;
	
	while(first <= last) {
		// cout << first << ' ' << mid << ' ' << last << '\n';
		mid = (first + last)/2;
		
		if(num_list[mid] == target) {
			return 1;
		}
		else {
			if(num_list[mid] > target)
				last = mid - 1;
			else
				first = mid + 1;
		}
	}
	return 0;
}

int main(void) {
	int n = 0;
	cin >> n;
	num_list.reserve(n);
	for(int i = 0; i < n; i++) {
		int tmp = 0;
		cin >> tmp;
		num_list.push_back(tmp);
	}
	
	int m = 0;
	cin >> m;
	for(int i = 0; i < m; i++) {
		int tmp = 0;
		cin >> tmp;
		ex.push_back(tmp);
	}
	
	vector<int>::iterator iter;
	sort(num_list.begin(), num_list.end());
	for(iter = ex.begin(); iter != ex.end(); iter++) {
		cout << search(*iter) << '\n';
	}
	
	return 0;
}


