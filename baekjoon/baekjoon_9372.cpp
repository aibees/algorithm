#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge {
	int src, des, value;
	bool operator < (edge const &e) {
		return (value < e.value);
	}
};

vector<edge> container;
vector<int> parent, set_size;
int T, N, M;

int find(int vertex) {
	if(vertex == parent[vertex])
		return vertex;
		
	return parent[vertex] = find(parent[vertex]);
}

void merge(int src, int des) {
	int root1 = parent[src];
	int root2 = parent[des];
	
	if(root1 != root2) {
		if(set_size[root1] <  set_size[root2]) {
			int tmp = root1;
			root1 = root2;
			root2 = tmp;
		}
		
		parent[root2] = root1;
		set_size[root1] += set_size[root2];
		set_size[root2] = 0;
	}
}

int main(void) {
	cin >> T;
	for(int i = 0; i < T; i++) {
		int answer = 0;
		cin >> N >> M;
		parent.resize(N+1);	set_size.resize(N+1);
		for(int j = 0; j < N+1; j++) {
			parent[j] = j;
			set_size[j] = 0;
		}
		
		container.reserve(M);
		container.clear();
		for(int j = 0; j < M; j++) {
			int s, d;	cin >> s >> d;
			container.push_back( {s, d, 1} );
		}
		sort(container.begin(), container.end());
		
		for(int j = 0; j < container.size(); j++) {
			edge e = container[j];
			if(parent[e.src] != parent[e.des]) {
				answer++;
				merge(e.src, e.des);
			}
		}
		cout << answer << '\n';
	}
	return 0;
}
