#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> d1; 
map<int, string> d2;
int n = 0, m = 0;

bool isNum(string t) {
	int a = t[0] - '0';
	if(a >= 0 && a <= 9)
		return true;
	return false;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	int cnt = 1;
	for(int i = 0; i < n; i++) {
		string name;
		cin >> name;
		d1[name] = cnt;
		d2[cnt] = name;
		cnt++;
	}
	for(int i = 0; i < m; i++) {
		string t;
		cin >> t;
		if(isNum(t)) {
			cout << d2.find(stoi(t))->second << '\n';
		}
		else {
			cout << d1.find(t)->second << '\n';
		}
	}
	return 0;
}