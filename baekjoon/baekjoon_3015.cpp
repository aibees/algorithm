#include <iostream>
#include <stack>
#include <utility>

using namespace std;

stack<pair<int, int> > s;
long long answer = 0;

int main(void) {
	int n = 0;	cin >> n;
	
	for(int i = 0; i < n; i++) {
		int h = 0; cin >> h;
		while(!s.empty() && s.top().first < h) {
			answer += s.top().second;
			s.pop();
		}
		
		if(s.empty()) {
			s.push(make_pair(h, 1));
		}
		else {
			if(s.top().first == h) {
				pair<int, int> current = s.top();
				s.pop();
				
				answer += current.second;
				if(!s.empty())
					answer++;
				
				current.second++;
				s.push(current);
			}
			else {
				s.push(make_pair(h, 1));
				answer++;
			}
		}
	}
	cout << answer << '\n';
	return 0;
}