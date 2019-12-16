#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, M, answer = 64;
bool Black = false;
vector<string> board;

int main(void) {
	cin >> N >> M;
	cin.ignore(256, '\n');
	
	for(int i = 0; i < N; i++) {
		string str;
		getline(cin, str);
		board.push_back(str);
	}
	
	// 맨 왼쪽 위의 색을 확인 
	if(board[0][0] == 'B')
		Black = true;
		
	bool check[N][M];
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++)
			check[i][j] = false;
	}
	
	for(int i = 0; i < board.size(); i++) {
		for(int j = 0; j < board[i].size(); j++) {
			if(Black) { // 첫 번째 시작하는 칸이 블랙  
				if((i + j) % 2 == 0) { // 첫번째 칸과 같은 색  
					if(board[i][j] != 'B')
						check[i][j] = true;
				}
				else { // 첫 번째 칸과 다른 색  
					if(board[i][j] != 'W')
						check[i][j] = true;
				}
			}
			else { // 첫 번째 시작하는 칸이 화이트  
				if((i + j) % 2 == 0) {
					if(board[i][j] != 'W')
						check[i][j] = true;
				}
				else {
					if(board[i][j] != 'B')
						check[i][j] = true;
				}
			}
		}
	}
	
	for(int i = 0; i <= N-8; i++) {
		for(int j = 0; j <= M-8; j++) {
			//8 * 8 크기로 1 더하면서 크기 계산
			int tmp = 0;
			for(int x = 0; x < 8; x++) {
				for(int y = 0; y < 8; y++) {
					if(check[i + x][j + y] == 1)
						tmp++;
				}
			}
			if(tmp > 32)
				tmp = 64 - tmp;
			if(tmp < answer)
				answer = tmp;
		}
	}
	
	cout << answer << '\n';
	return 0;
}

