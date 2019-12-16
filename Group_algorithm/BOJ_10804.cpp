#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

void process(int b, int e) {
	int j = 0;
	vector<int> tmp;
	tmp.assign(arr.begin()+b, arr.begin()+e+1);
	for(int i = e; i > b-1; i--) {
		arr[i] = tmp[j];
		j++;
	}
}

int main(void) {
	arr.resize(21, 0);
	for(int i = 0; i < 21; i++) {
		arr[i] = i;
	}
	
	int begin = -1, end = -1;
	for(int i = 0; i < 10; i++) {
		cin >> begin >> end; 
		process(begin, end);
	}
	
	for(int i = 1; i <= 20; i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';
		
	return 0;
}
