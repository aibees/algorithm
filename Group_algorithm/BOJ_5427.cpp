#include <iostream>
#include <queue>
#include <utility>
#include <string.h>

using namespace std;

char building[1001][1001] = {' ', };
bool visited[1001][1001] = {false, };
queue<pair<int, int> > sg, fire;
pair<int, int> start;
int M, N, answer = -1;
int X[4] = {-1, 0, 1, 0};
int Y[4] = {0, -1, 0, 1};

void clearQueue(queue<pair<int, int> > &q) {
	queue<pair<int, int> > empty;
	swap(q, empty);
}

void process() {
	int time = 0;
	
	while(!sg.empty() || !fire.empty()) {
		// first, fire
		//cout << "\n==============\n";
		int fire_size = fire.size();
		while(fire_size-- > 0) {
			pair<int, int> cur = fire.front();
			fire.pop();
			//cout << "fire cur : ( " << cur.first << ", " << cur.second << " )\n";
			for(int i = 0; i < 4; i++) {
				int nx = cur.first + X[i];
				int ny = cur.second + Y[i];
				
				if(nx < 0 || ny < 0 || nx >= N || ny >= M || building[nx][ny] == '@' || building[nx][ny] == '#') {
					continue;
				}
				//cout << "fire next : ( " << nx << ", " << ny << " )\n";
				if(building[nx][ny] == '.' && !visited[nx][ny]) { // firing
					visited[nx][ny] = true;
					building[nx][ny] = '*';
					fire.push(make_pair(nx, ny));
				}
			}
		}
		// second, sg
		
		//cout << "\n==============\n";
		bool ex_flag = false;
		int sg_size = sg.size();
		while(sg_size-- > 0) {
			pair<int, int> cur = sg.front();
			sg.pop();
			//cout << "sg cur : ( " << cur.first << ", " << cur.second << " )\n";
			if(cur.first == 0 || cur.second == 0 || cur.first == N-1 || cur.second == M-1) {
				ex_flag = true;
				//cout << "true\n";
				break;
			}
			
			for(int i = 0; i < 4; i++) {
				int nx = cur.first + X[i];
				int ny = cur.second + Y[i];
				if(nx < 0 || ny < 0 || nx >= N || ny >= M || building[nx][ny] == '*' || building[nx][ny] == '#') {
					continue;
				}
				
				//cout << "sg next : ( " << nx << ", " << ny << " )\n";
				if(building[nx][ny] == '.' && !visited[nx][ny]) { // firing
					visited[nx][ny] = true;
					building[nx][ny] = '@';
					sg.push(make_pair(nx, ny));
				}
			}
		}
		time++;
		if(ex_flag) {
			answer = time;
			break;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	cin >> T;
	
	while(T-- > 0) {
		clearQueue(sg);
		clearQueue(fire);
		memset(visited, false, sizeof(visited));
		answer = -1;
		
		cin >> M >> N;
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				char tmp;
				cin >> tmp;
				building[i][j] = tmp;
				
				if(tmp == '@') {
					start = make_pair(i, j);
					sg.push(start);
					visited[i][j] = true;
				}
				if(tmp == '*') {
					fire.push(make_pair(i, j));
					visited[i][j] = true;
				}
			}
		}
		if(start.first == 0 || start.second == 0 || start.first == N-1 || start.second == M-1) {
			cout << 1 << '\n';
			continue;
		}
		process();
		
		if(answer == -1) {
			cout << "IMPOSSIBLE\n";
		}
		else {
			cout << answer << '\n';
		}
	}
	
	return 0;
}
