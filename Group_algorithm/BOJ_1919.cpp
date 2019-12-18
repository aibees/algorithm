#include <iostream>
#include <cmath>

using namespace std;

int alphabet[26] = {0, };

int main(void) {
	
	string t1, t2;
	int answer = 0;
	cin >> t1 >> t2;
	
	for(int i = 0; i < t1.size(); i++) {
		alphabet[t1[i] - 'a']++;
	}
	for(int i = 0; i < t2.size(); i++) {
		
		alphabet[t2[i] - 'a']--;
	}
	for(int i = 0; i < 26; i++) {
		if(alphabet[i] != 0) {
			answer += abs(alphabet[i]);
		}
	}
	
	cout << answer << '\n';
	return 0;
}
