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
	//root�� �ڱ��ڽ��̸� �״�� �ڽ��� ���  
	if(vertex == parent[vertex])
		return vertex;
	
	// ��������� vertex�� root�� ������Ʈ�ϸ鼭 ��� ���� return 
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
	// value�� �������� sorting 
	sort(e_container.begin(), e_container.end());
	
	// init
	for(int i = 0; i < V+1; i++) {
		parent[i] = i;
	}
	
	// start algorithm loop
	for(int i = 0; i < e_container.size(); i++) {
		edge e = e_container[i];
		// edge�� src�� des�� ���� �ٸ� �׷� (��, ���������� �� cyclic�� ���� �ʵ���)�϶��� answer�� + 
		if(findRoot(e.src) != findRoot(e.des)) {
			answer += e.value;
			//���� ���� �׷����� �����ش� 
			merge(e.src, e.des);
		}
	}
	
	cout << answer << '\n';
	return 0;
}

