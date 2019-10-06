#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int d_h, d_w, K, O;
vector<vector<char> > draw;
map<int, vector<vector<char> > > stamps;

void process(int num, int y, int x) {
	vector<vector<char> > stamp = stamps[num];
	for(int i = 0; i < stamp.size(); i++) {
		vector<char> row = stamp[i];
		for(int j = 0; j < row.size(); j++) {
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
	for(int i = 0; i < d_h; i++) {
		vector<char> draw_row;	draw_row.reserve(d_w);
		for(int j = 0; j < d_w; j++) {
			draw_row.push_back('.');
		}
		draw.push_back(draw_row);
	}
	cin >> K;
	
	// get stamps
	for(int i = 1; i < K+1; i++) {
		int stamp_h, stamp_w;
		cin >> stamp_h >> stamp_w;
		vector<vector<char> > stamp;	stamp.reserve(stamp_h);
		
		for(int j = 0; j < stamp_h; j++) {
			vector<char> c_tmp;	c_tmp.reserve(stamp_w);
			
			for(int k = 0; k < stamp_w; k++) {
				char tmp;	cin >> tmp;
				c_tmp.push_back(tmp);
			}
			stamp.push_back(c_tmp);
			c_tmp.clear();
		}
		stamps[i] = stamp;
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
