#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    answer.resize(heights.size(), 0);
    for(int i = heights.size()-1; i > 0; i--) {
        for(int j = i - 1; j > -1; j--) {
            if(heights[i] < heights[j]) {
                answer[i] = j+1;
                break;
            }
        }
    }
    return answer;
}