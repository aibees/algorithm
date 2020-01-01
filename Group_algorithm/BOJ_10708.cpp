#include <iostream>

using namespace std;

int n, m;
int friends[101] = {0, };
int mafia[101] = {0, };

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		cin >> mafia[i];
	}
	
	for(int i = 1; i <= m; i++) {
		int target = mafia[i];
		int miss = 0;
		for(int j = 1; j <= n; j++) {
			int tmp;	cin >> tmp;
			if(tmp == target) {
				friends[j]++;
			}
			else {
				miss++;
			}
		}
		friends[target] += miss;
	}
	
	for(int i = 1; i <= n; i++) {
		cout << friends[i] << '\n';
	}
	return 0;
}
