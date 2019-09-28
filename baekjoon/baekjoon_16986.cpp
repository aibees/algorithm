#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<vector<int> > graph;
vector<int> minho, kyunghee;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> k;
	graph.reserve(n);
	for(int i = 0; i < n; i++) {
		vector<int> tmp; tmp.reserve(n);
		for(int j = 0; j < n; j++) {
			int t = 0; cin >> t;
			tmp.push_back(t);
		}
		graph.push_back(tmp);
	}
	minho.reserve(20); kyunghee.reserve(20);
	for(int i = 0; i < 20; i++) {
		int t = 0; cin >> t;
		kyunghee.push_back(t);
	}
	for(int i = 0; i < 20; i++) {
		int t = 0; cin >> t;
		minho.push_back(t);
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << graph[i][j] << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}
