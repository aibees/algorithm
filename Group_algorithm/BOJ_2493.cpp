#include <iostream>
#include <stack>
#include <vector>
#include <utility>

using namespace std;

vector<int> answer;
stack<pair<int, int> > st;

int main(void) {
	int tower;
	cin >> tower;
	
	for(int t = 1; t <= tower; t++) {
		int h;
		cin >> h;
		
		if(st.size() == 0) {
			answer.push_back(0);
			st.push(make_pair(t, h));
			continue;
		}
		
		while(true) {
			pair<int, int> before;
			
			if(st.size() == 0) {
				answer.push_back(0);
				st.push(make_pair(t, h));
				break;
			}
			else {
				before = st.top();
			}
			if(before.second > h) {
				answer.push_back(before.first);
				st.push(make_pair(t, h));
				break;
			}
			else if(before.second < h) {
				st.pop();
				continue;
			}
		}
	}
	
	for(int i = 0; i < answer.size(); i++) {
		cout << answer[i] << ' ';
	}
	
	return 0;
}
