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
	cin >> T;
	
	while(T-- > 0) {
		c_left.clear();
		c_right.clear();
		cin >> input;
		
		for(int i = 0; i < input.size(); i++) {
			char next = input[i];
			
			if(next == '<') {
				if(c_left.size() > 0) {
					c_right.push_front((c_left.back()));
					c_left.pop_back();
				}
			}
			else if(next == '>') {
				if(c_right.size() > 0) {
					c_left.push_back((c_right.front()));
					c_right.pop_front();
				}
			}
			else if(next == '-') {
				if(c_left.size() > 0) {
					c_left.pop_back();
				}
			}
			else {
				c_left.push_back(next);
			}
		}
		print();
	}
	
	return 0;
}
