#include <iostream>
#include <vector>

using namespace std;

int T;

int main(void) {
	cin >> T;
	
	for(int test_case = 1; test_case <= T; test_case++) {
		int N, M, cut = 1;
		cin >> N >> M;
		while(true) {
			if(cut > M)
				break;
			cut *= 10;
		}
		cut *= 10;
		vector<long long> nums;	nums.resize(N+1);
		nums[0] = 0;	nums[1] = 1;
		for(int i = 2; i <= N; i++) {
			nums[i] = (nums[i-1]*nums[i-1]*nums[i-1]) + (nums[i-2]*nums[i-2]*nums[i-2]);
			if(nums[i] > cut)
				nums[i] = nums[i] % cut;
		}
		
		int answer = nums[N] % M;
		
		for(int i = 0; i < nums.size(); i++)
			cout << nums[i] << ' ';
		cout << '\n';
		for(int i = 0; i < nums.size(); i++)
			cout << nums[i] % M << ' ';
		cout << '\n';
		cout << "#" << test_case << ' ' << answer << '\n';
	}
	
	return 0;
}
