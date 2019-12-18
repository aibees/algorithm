#include <iostream>
#include <deque>

using namespace std;

deque<char> c_left, c_right;

void print() {
		
	for(int i = 0; i < c_left.size(); i++) {
		cout << c_left[i];
	}
	for(int i = 0; i < c_right.size(); i++) {
		cout << c_right[i];
	}
	cout << '\n';
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T = 0;
	string input;
	cin >> input;
	cin >> T;
	
	for(int i = 0; i < input.size(); i++) {
		c_left.push_back(input[i]);
	}
	
	for(int t_case = 0; t_case < T; t_case++) {
		char order;	cin >> order;
		
		if(order == 'L') {
			if(c_left.size() > 0) {
				c_right.push_front((c_left.back()));
				c_left.pop_back();
			}
		}
		else if(order == 'D') {
			if(c_right.size() > 0) {
				c_left.push_back((c_right.front()));
				c_right.pop_front();
			}
		}
		else if(order == 'B') {
			if(c_left.size() > 0) {
				c_left.pop_back();
			}
			else {
				continue;
			}
		}
		else if(order == 'P') {
			char tmp;	cin >> tmp;
			c_left.push_back(tmp);
		}
	}
	print();
	
	return 0;
}
