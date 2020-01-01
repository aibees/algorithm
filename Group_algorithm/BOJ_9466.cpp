/*
	2019-12-29
	BOJ_9466
	written by aibees1129
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<int, int> proj;
vector<bool> visited;
int student;

void process(int start) {
	vector<int> visited_tmp;
	int cur = start, result = -1;
	visited_tmp.push_back(cur);
	
	while(true) {
		if(proj.find(cur) == proj.end() || visited[proj[cur]]) { // cur th student selected themself
			break;
		}
		int next = proj[cur];
		
		if(proj.find(next) != proj.end()) {
			result = next;
			break;
		}
		
		visited_tmp.push_back(next);
		cur = next;
	}
	
	cur = result;
	int next = 0;
	cout << "visited check : ";
	do {
		cout << cur << ' ';
		next = proj[cur];
		visited[next] = true;
		cur = next;
	} while(result != next);
	cout << '\n';
	return;
}
		
int main(void) {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
	
	int T;
	cin >> T;
	for(int test_case = 0; test_case < T; test_case++) {
		cout << "test case : " << test_case << '\n';
		cin >> student;
		proj.clear();
		visited.clear();
		visited.resize(student+1, false);
		
		for(int t = 1; t <= student; t++) {
			int want;	cin >> want;
			if(t == want) { // check self selection
				visited[t] = true;
			}
			else {
				proj[t] = want;
			}
		}
		
//		cout << "proj size : " << proj.size() << '\n';
//		for(map<int, int>::iterator it = proj.begin(); it != proj.end(); it++) {
//			cout << "std : " << it->first << ", want : " << it->second << '\n'; 
//		}
		
		for(int t = 1; t <= student; t++) {
			if(!visited[t]) {
				process(t);
			}
		}
		
		int answer = 0;
		for(int t = 1; t < visited.size(); t++) {
			if(!visited[t]) {
				answer++;
			}
		}
		
		cout << answer << '\n';
	}
	
	return 0;
}
