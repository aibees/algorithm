#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<int> bridge, cnt;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, w = weight;
    bridge.reserve(truck_weights.size()); cnt.reserve(truck_weights.size());
    auto it = truck_weights.begin();
    while(true) {
        answer++;
        for(int i = 0; i < cnt.size(); i++) {
            cnt[i]++;
        }
        if(cnt.front() == bridge_length && bridge.size() > 0) { // out
            weight += bridge.front();
            bridge.erase(bridge.begin());
            cnt.erase(cnt.begin());
        }
        if(it != truck_weights.end() && weight >= (*it)) { // in
            bridge.push_back((*it));
            cnt.push_back(0);
            weight -= (*(it));
            it++;
        }
        if(it == truck_weights.end() &&  w == weight)
            break;
    }
    return answer;
}