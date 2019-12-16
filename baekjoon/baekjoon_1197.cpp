#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge {
	int src;
	int des;
	long value;
	
	bool operator < (edge const &e) {
		return value < e.value;
	}
};

vector<int> parent, group_size;
vector<edge> e_container;
int V, E;

int findRoot(int vertex) {
	//root가 자기자신이면 그대로 자신을 출력  
	if(vertex == parent[vertex])
		return vertex;
	
	// 재귀적으로 vertex의 root를 업데이트하면서 결과 값을 return 
	return parent[vertex] = findRoot(parent[vertex]);
}

void merge(int src, int des) {
	int root1 = findRoot(src);
	int root2 = findRoot(des);
	
	if(root1 != root2) {
		if(group_size[root1] <  group_size[root2]) {
			int tmp = root1;
			root1 = root2;
			root2 = tmp;
		}
		
		parent[root2] = root1;
		group_size[root1] += group_size[root2];
		group_size[root2] = 0;
	}
	return;
} 

int main(void) {
	long long answer = 0;
	cin >> V >> E;
	parent.resize(V+1);
	group_size.resize(E+1);
	for(int i = 0; i < E; i++) {
		int s, d, v;
		cin >> s >> d>> v;
		e_container.push_back( {s, d, v} );
	}
	// value를 기준으로 sorting 
	sort(e_container.begin(), e_container.end());
	
	// init
	for(int i = 0; i < V+1; i++) {
		parent[i] = i;
	}
	
	// start algorithm loop
	for(int i = 0; i < e_container.size(); i++) {
		edge e = e_container[i];
		// edge의 src와 des가 서로 다른 그룹 (즉, 연결지었을 때 cyclic이 되지 않도록)일때만 answer에 + 
		if(findRoot(e.src) != findRoot(e.des)) {
			answer += e.value;
			//둘을 같은 그룹으로 묶어준다 
			merge(e.src, e.des);
		}
	}
	
	cout << answer << '\n';
	return 0;
}

