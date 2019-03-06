#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> num;
int tmp;
int cnt = 0;
bool func(vector<int> v, int i) {
    for(auto it = v.begin(); it != v.end(); it++) {
        if(i < (*it))
            return true;
    }
    return false;
}

int solution(vector<int> priorities, int location) {
    num.resize(priorities.size());
    for(int i = 0; i < priorities.size(); i++) { num[i] = i; }

    while(true) {
        tmp = priorities.front();   priorities.erase(priorities.begin());
        if(func(priorities, tmp)) { //최고 순서 x
            priorities.push_back(tmp);
            num.push_back(num.front());
            num.erase(num.begin());
        }
        else { // 최고 순서
            cnt++;
            if(location == num.front()) {
                break;
            }
            num.erase(num.begin());
        }
    }
    return cnt;
}