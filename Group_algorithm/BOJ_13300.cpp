#include<iostream>

using namespace std;

int room[7][2] = {0, };
int n, k;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> k;
	
	while(n-- > 0) {
		int gender, grade;
		cin >> gender >> grade;
		
		room[grade][gender]++;
	}
	
	int answer = 0;
	
	for(int i = 1; i <= 6; i++) {
		int w = room[i][0];
		int m = room[i][1];
		
		answer += (room[i][0]/k + room[i][1]/k);
		if(w%k > 0) { answer++; }
		if(m%k > 0) { answer++; }
	}
	
	cout << answer << '\n';
	return 0;
}
