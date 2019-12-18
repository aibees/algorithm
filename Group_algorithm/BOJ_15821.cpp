#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

priority_queue<double, vector<double>, greater<double> > dist;
int N, M;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> M;
	
	for(int i = 0; i < N; i++) {
		int arc;
		cin >> arc;
		
		//도형 별 최대 거리 구하기
		double Max = 0; 
		for(int j = 0; j < arc; j++) {
			long long x, y;
			cin >> x >> y;
			double d = (double)sqrt((x*x) + (y*y));
			if(Max < d)
				Max = d;		
		}
		dist.push(Max);
	}
	double answer;
	for(int m = 0; m < M; m++) {
		answer = dist.top();
		dist.pop();
	}
	printf("%.2f\n", answer*answer);
	return 0;
}
