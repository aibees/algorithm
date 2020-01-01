/*
	2019-12-29
	BOJ_2667
	written by aibees1129
*/

#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

priority_queue<int, vector<int>, greater<int> > size;
bool map[26][26] = {false, };
bool visited[26][26] = {false, };
int K, answer = 0;
int X[4] = {-1, 0, 1, 0};
int Y[4] = {0, -1, 0, 1};

void process(int s_i, int s_j) {
	int cnt = 1;
	queue<pair<int, int> > q;
	q.push(make_pair(s_i, s_j));
	visited[s_i][s_j] = true;
	
	while(!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		
		for(int i = 0; i < 4; i++) {
			int nx = cur.first + X[i];
			int ny = cur.second + Y[i];
			
			if(nx < 0 || ny < 0 || nx >= K || ny >= K || visited[nx][ny]) {
				continue;
			}
			
			if(map[nx][ny] && !visited[nx][ny]) {
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
				cnt++;
			}
		}
	}
	size.push(cnt);
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	// input
	cin >> K;
	
	for(int i = 0; i < K; i++) {
		for(int j = 0; j < K; j++) {
			char tmp;
			cin >> tmp;
			if(tmp == '1')
				map[i][j] = true;
		}
	}
	
	// get group of house
	for(int i = 0; i < K; i++) {
		for(int j = 0; j < K; j++) {
			if(map[i][j] && !visited[i][j]) {
				process(i, j);
				answer++;
			}
		}
	}
	
	// output
	cout << answer << '\n';
	while(!size.empty()) {
		int tmp = size.top();
		size.pop();
		cout << tmp << '\n';
	}
	
	return 0;
}
