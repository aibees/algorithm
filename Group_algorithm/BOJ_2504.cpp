#include <iostream>
#include <stack>

using namespace std;

stack<char> bracket;
stack<int> num;

int main(void) {
	string input;
	cin >> input;
	
	int answer = 0;
	
	for(int i = 0; i < input.size(); i++) {
		char t = input[i];
		if(t == '(' || t == '[') {
			bracket.push(t);
		}
		else if(t == ')') {
			if(bracket.size() == 0) {
				cout << 0 << '\n';
				return 0;
			}
			
			if(bracket.top() == '(') {
				bracket.pop();
				bracket.push('n');
				num.push(2);
			}
			else if(bracket.top() == '[') {
				cout << 0 << '\n';
				return 0;
			}
			else if(bracket.top() == 'n') { // numbers;
				int ac = 0;
				while(true) {
					if(bracket.size() == 0) {
						cout << 0 << '\n';
						return 0;
					}
					
					if(bracket.top() == 'n') {
						ac += num.top();
						bracket.pop();
						num.pop();
					}
					else {
						if(bracket.top() == '(') {
							bracket.pop();
							bracket.push('n');
							num.push(ac*2);
						}
						else if(bracket.top() == '[') {
							cout << 0 << '\n';
							return 0;
						}
						break;
					}
				}
			}
		}
		else if(t == ']') {
			if(bracket.size() == 0) {
				cout << 0 << '\n';
				return 0;
			}
			
			if(bracket.top() == '[') {
				bracket.pop();
				bracket.push('n');
				num.push(3);
			}
			else if(bracket.top() == '(') {
				cout << 0 << '\n';
				return 0;
			}
			else if(bracket.top() == 'n') { // numbers;
				int ac = 0;
				while(true) {
					if(bracket.size() == 0) {
						cout << 0 << '\n';
						return 0;
					}
					
					if(bracket.top() == 'n') {
						ac += num.top();
						bracket.pop();
						num.pop();
					}
					else {
						if(bracket.top() == '(') {
							cout << 0 << '\n';
							return 0;
						}
						else if(bracket.top() == '[') {
							bracket.pop();
							bracket.push('n');
							num.push(ac*3);
						}
						break;
					}
				}
			}
		}
//		cout << "t : " << t << '\n';
//		cout << "stack size : " << bracket.size() << '\n';
//		cout << "stack top : " << bracket.top() << '\n';
//		cout << "num top : " << ((num.empty()? (-1):(num.top()))) << "\n\n";
	}
	while(!num.empty()) {
		answer += num.top();
		num.pop();
	}
	bool flag = false;
	while(!bracket.empty()) {
		if(bracket.top() != 'n')
			flag = true;
		bracket.pop();
	}
	
	if(flag) {
		cout << 0 << '\n';
		return 0;
	}
	cout << answer << '\n';
	return 0;
}
