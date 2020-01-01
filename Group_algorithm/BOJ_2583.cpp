/*
	2019-12-29
	BOJ_2583
	written by aibees1129
*/

#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

priority_queue<int, vector<int>, greater<int> > size;
bool paper[101][101] = {false, };
bool visited[101][101] = {false, };
int N, M, K, answer = 0;
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
			
			if(nx < 0 || ny < 0 || nx >= M || ny >= N || visited[nx][ny]) {
				continue;
			}
			
			if(!paper[nx][ny] && !visited[nx][ny]) {
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
	cin >> M >> N >> K;
	
	for(int t = 0; t < K; t++) {
		int x1, y1, x2, y2;
		
		cin >> x1 >> y1 >> x2 >> y2;
		
		for(int i = y1; i < y2; i++) {
			for(int j = x1; j < x2; j++) {
				paper[i][j] = true;
			}
		}
	}
	
	// get empty space
	for(int i = 0; i < M; i++) {
		for(int j = 0; j < N; j++) {
			if(!paper[i][j] && !visited[i][j]) {
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
		cout << tmp << ' ';
	}
	
	return 0;
}
