#include <iostream>
#include <map>

using namespace std;

int answer = 0;
long long limit = 0;

void dfs(char cur, long long acc, int cnt, map<int, int> stacks) {
	if(cur == '*') {
		// stack
		stacks[++cnt] = 3;
		//accumulate
		acc *= 3;
		
		if(acc > limit) {
			cout << "acc : " << acc << " - limit overwhelmed" << '\n';
			return;
		}
	}
	else if(cur == '+') {
		// 사전차단 
		if(cnt == -1) {
			cout << "stack underflow" << '\n';
			return; 
		}
		// stack
		int tmp = stacks[cnt];
		if(tmp == 3) {
			tmp++;
			stacks.erase(cnt);
			stacks[cnt] = tmp;
		}
		else if(tmp == 4) { // stack down
			stacks.erase(cnt);
			cnt--;
		}
		//accumulate
		acc++;
		// return abnormally
		if(acc > limit || (acc == limit && cnt > -1)) {
			cout << "acc : " << acc << " - limit overwhelmed" << '\n';
			return;
		}
		
		// return normally
		if(acc == limit && cnt == -1) {
			answer++;
			cout << "answer : " << answer << '\n';
		}
	}
	cout << "acc : " << acc << '\n';
	//next
	dfs('*', acc, cnt, stacks);
	dfs('+', acc, cnt, stacks);
	return;
}

int solution(int n) {
	limit = n;
	map<int, int> stacks;
	dfs('*', 1, -1, stacks);
	int result = answer;
	return result;
}

int main(void) {
	int n = 0;
	
	do {
		cin >> n;
		answer = 0;
		cout << solution(n) << '\n';
	} while(n != 0);
	
	return 0;
}
