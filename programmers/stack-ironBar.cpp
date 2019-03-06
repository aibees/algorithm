#include <string>
#include <vector>

using namespace std;

int stack = 0;

int solution(string arrangement) {
    int answer = 0;
    auto it = arrangement.begin();
    while(it != arrangement.end()) {
        char i = (*it);
        if(i == '(') {
            stack++;
        }
        else {
            if((*(it-1)) == '(') {
                answer += (stack-1);
            }
            else {
                answer++;
            }
            stack--;
        }
        it++;
    }
    return answer;
}