#include <iostream>
#include <stack>
#include <utility>

using namespace std;

int n, m;
int X[4] = {-1, 0, 1, 0};
int Y[4] = {0, -1, 0, 1};
int board[501][501] = {0, };
bool visited[501][501] = {false, };

int cnt = 0, answer = 0;

void process(int i, int j) {
	int size = 0;
	stack<pair<int, int> > st;
	st.push(make_pair(i, j));
	visited[i][j] = true;
	
	while(!st.empty()) {
		pair<int, int> cur = st.top();
		st.pop();
		
		size++;
		
		for(int i = 0; i < 4; i++) {
			int nx = cur.first + X[i];
			int ny = cur.second + Y[i];
			
			if(nx < 0 || ny < 0 || nx >= n || ny >= m) {
				continue;
			}
			
			if(board[nx][ny] == 1 && !visited[nx][ny]) {
				st.push(make_pair(nx, ny));
				visited[nx][ny] = true;
			}
		}
	}
	
	//cout << "i : " << i << ", j : " << j << " -> " << size << '\n';
	
	if(answer < size) {
		answer = size;
	}
	
	return;
}

int main(void) {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(board[i][j] == 1 && !visited[i][j]) {
				process(i, j);
				cnt++;
			}
		}
	}
	
	cout << cnt << '\n' << answer << '\n';
	
	return 0;
}
