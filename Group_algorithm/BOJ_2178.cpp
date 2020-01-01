#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int graph[101][101] = {0, };
bool visited[101][101] = {false, };
int X[4] = {-1, 0, 1, 0};
int Y[4] = {0, -1, 0, 1};
int N, M, answer = 0;


void process(int start_i, int start_j) {
	bool flag = false;
	
	queue<pair<int, int> > q;
	q.push(make_pair(start_i, start_j));
	visited[start_i][start_j] = true;
	
	while(!q.empty()) {
		int q_size = q.size();
		answer++;
		
		for(int qs = 0; qs < q_size; qs++) {
			pair<int, int> cur = q.front();
			q.pop();
			
			if(cur.first == N && cur.second == M) {
				flag = true;
				break;
			}
			
			for(int i = 0; i < 4; i++) {
				int nx = cur.first + X[i];
				int ny = cur.second + Y[i];
				
				if(nx < 0 || ny < 0 || nx > N || ny > M) {
					continue;
				}
				
				if(graph[nx][ny] == 1 && !visited[nx][ny]) {
					q.push(make_pair(nx, ny));
					visited[nx][ny] = true;
				}
			}
		}
		
		if(flag) {
			break;
		}
	}
	
	return ;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> M;
	
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			char tmp;
			cin >> tmp;
			graph[i][j] = (tmp - '0');
		}
	}
	// input end
	
	process(1, 1);
	
	cout << answer << '\n';
	return 0;
}
