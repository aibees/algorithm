#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent;
vector<long long> set_size;
int T, N;

int findParent(int v) {
	// �ܼ��� root���� �ö󰡱� ���� �뵵�̱⵵ ������
	// ������ root���� �ö󰬴� node���� parent�� root�� ������ �ִٸ�
	// �� �������� �ش� node���� �ٽ� root���� �ö� �ʿ� ���� �ش� size�� ������ ���� �ȴ�. 
	if(parent[v] == v) {
		return v;
	}
	else {
		int des = findParent(parent[v]);
		set_size[v] += set_size[parent[v]];
		// �ش� node�� root�� ��� �ö�Դٴ� �ǹ� 
		// �������ʹ� �� �̻� �ö� �ʿ䰡 ����
		parent[v] = des;
		
		return des;
	}
}

void merge(int src, int des) {
	// �� vertex�� root���� ã�� �����ϴ� �Ϲ����� ��Ʈ��ũ ���� �˰������ �޸�
	// �ش� ���������� �ϳ��� ��带 �߰� ��忡 �����ϴ� �۾��� �ֱ⿡ destination�� �״�� �־� �� 
	parent[src] = des;
	// �޸������̼�  
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
		// ���� �𸣰� �� �տ� ������ ���� �ֱ淡 �������� 
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
