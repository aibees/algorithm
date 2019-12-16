#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent;
vector<long long> set_size;
int T, N;

int findParent(int v) {
	// 단순히 root까지 올라가기 위한 용도이기도 하지만
	// 이전에 root까지 올라갔던 node또한 parent로 root를 가지고 있다면
	// 그 다음부턴 해당 node부터 다시 root까지 올라갈 필요 없고 해당 size만 가지고 오면 된다. 
	if(parent[v] == v) {
		return v;
	}
	else {
		int des = findParent(parent[v]);
		set_size[v] += set_size[parent[v]];
		// 해당 node는 root를 찍고 올라왔다는 의미 
		// 다음부터는 이 이상 올라갈 필요가 음슴
		parent[v] = des;
		
		return des;
	}
}

void merge(int src, int des) {
	// 각 vertex의 root들을 찾아 연결하는 일반적인 네트워크 연결 알고리즘과는 달리
	// 해당 문제에서는 하나의 노드를 중간 노드에 연결하는 작업이 있기에 destination은 그대로 둬야 함 
	parent[src] = des;
	// 메모이제이션  
	set_size[src] = abs(src - des) % 1000;
}

vector<string> split(string str, char delimeter) {
	vector<string> splits;
	stringstream ss(str);
	string tmp;
	
	while(getline(ss, tmp, delimeter)) {
		splits.push_back(tmp);
	}
	
	return splits;
}

int main(void) {
	cin >> T;
	for(int i = 0; i < T; i++) {
		cin >> N;
		parent.clear(); set_size.clear();
		parent.resize(N+1);	set_size.resize(N+1);
		vector<vector<string> > order_list;
		do {
			string tmp; getline(cin, tmp);
			if(tmp == "O") { break; }
			else { order_list.push_back(split(tmp, ' ')); }
		} while(true);
		// 왠지 모르게 맨 앞에 쓰레기 값이 있길래 제거해줌 
		order_list.erase(order_list.begin());
		for(int i = 0; i < order_list.size(); i++) {
			vector<string> order = order_list[i];
			
			if(order[0] == "E") {
				int I = atoi(order[1].c_str());
				findParent(I);
				cout << set_size[I] << '\n';
			}
			else if(order[0] == "I") {
				int I = atoi(order[1].c_str());
				int J = atoi(order[2].c_str());
				if(parent[I] == 0)
					parent[I] = I;
				if(parent[J] == 0)
					parent[J] = J;
				merge(I, J);
			}
		}
	}
	return 0;
}
