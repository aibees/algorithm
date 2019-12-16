#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 11
#define POSITION_MAX 5

using namespace std;

vector<vector<int> > players;
int max_position[MAX][MAX];

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector<int> player;
	player.reserve(MAX);	players.reserve(MAX);
	// ==================== �Է� ======================= 
	int caseNum = 0;
	cin >> caseNum;
	for(int x = 0; x < caseNum; x++) {
		players.clear();
		for(int i = 0; i < MAX; i++) {
			player.clear();
			for(int j = 0; j < MAX; j++) {
				int tmp = 0;	cin >> tmp;
				player.push_back(tmp);
			}
			players.push_back(player);
		}
		// ----------------- �Է� ��--------------------
		 
		vector<int> position, tmp_list;
		
		for(int j = 0; j < MAX; j++) {
			
			for(int i = 0; i < POSITION_MAX; i++) {
				int p_max = 0;
				for(int k = 0; k < POSITION_MAX; k++) {
					if(j > 0)
						p_max = max(p_max, position[i] + max_position[j-1][k]);
					else {
						p_max = position[i];
					}
				}
				max_position[j][i] = p_max;
			}
		}
		
		for(int y = MAX-1; y >= 0; y--) {
			for(int z = 0; z < POSITION_MAX; z++) {
				cout << max_position[y][z] << ' ';
			}
			cout << '\n';
		}
	}
	
	return 0;
}
