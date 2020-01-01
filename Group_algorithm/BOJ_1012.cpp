#include <iostream>
#include <stack>
#include <utility>

using namespace std;

bool graph[51][51] = {false, };
bool visited[51][51] = {false, };
int X[4] = {-1, 0, 1, 0};
int Y[4] = {0, -1, 0, 1};
int N, M, K;

void process(int i, int j) {
	stack<pair<int, int> > st;
	st.push(make_pair(i, j));
	visited[i][j] = true;
	
	while(!st.empty()) {
		pair<int, int> cur = st.top();
		st.pop();
		
		for(int i = 0; i < 4; i++) {
			int nx = cur.first + X[i];
			int ny = cur.second + Y[i];
				
			if(nx < 0 || ny < 0 || nx > N || ny > M) {
				continue;
			}
			
			if(graph[nx][ny] && !visited[nx][ny]) {
				st.push(make_pair(nx, ny));
				visited[nx][ny] = true;
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	cin >> T;
	
	for(int test_case = 0; test_case < T; test_case++) {
		for(int i = 0; i <= N; i++) {
			for(int j = 0; j <= M; j++) {
				visited[i][j] = false;
				graph[i][j] = false;
			}
		}
		
		int answer = 0;
		
		cin >> N >> M >> K;
		for(int t = 0; t < K; t++) {
			int idx_x, idx_y;
			cin >> idx_x >> idx_y;
			graph[idx_x][idx_y] = true;
		}
		
		for(int i = 0; i <= N; i++) {
			for(int j = 0; j <= M; j++) {
				if(graph[i][j] && !visited[i][j]) {
					process(i, j);
					//cout << "test case : " << test_case << " -> " << answer << "in [ " << i << ", " << j << " ]" << '\n';
					answer++;
				}
			}
		}
		
		cout << answer << '\n';
	}
	return 0;
}
