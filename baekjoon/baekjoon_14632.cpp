#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

int d_h, d_w, K, O;
char draw[1001][1001];
map<int, vector<string> > stamps;
map<int, pair<int, int> > stamp_size;

void process(int num, int y, int x) {
	vector<string> stamp = stamps[num];
	auto size_p = stamp_size[num];
	for(int i = 0; i < size_p.first; i++) {
		for(int j = 0; j < size_p.second; j++) {
			if(i+y < d_h && j+x < d_w) {
				draw[i+y][j+x] = stamp[i][j];
			}
		}
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> d_h >> d_w;
	
	// draw init
	for(int i = 0; i < d_h; i++) {
		for(int j = 0; j < d_w; j++) {
			draw[i][j] = '.';
		}
	}
	
	// the number of stamps
	cin >> K;
	
	// get stamps
	for(int i = 1; i < K+1; i++) {
		int stamp_h, stamp_w;
		cin >> stamp_h >> stamp_w;
		vector<string> stamp;
		cin.ignore(256, '\n');
		for(int j = 0; j < stamp_h; j++) {
			string line;
			getline(cin, line);
			stamp.push_back(line);
		}
		stamps[i] = stamp;
		stamp_size[i] = make_pair(stamp_h, stamp_w);
	}
	
	// get orders
	cin >> O;
	for(int i = 0; i < O; i++) {
		int stamp_num, y, x;
		cin >> stamp_num >> y >> x;
		process(stamp_num, y, x);
	}
	
	for(int i = 0; i < d_h; i++) {
		for(int j = 0; j < d_w; j++) {
			cout << draw[i][j];
		}
		cout << '\n';
	}
	return 0;
}
