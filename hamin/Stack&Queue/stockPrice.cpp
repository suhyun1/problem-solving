#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    stack<int> time;
    vector<int> answer(prices.size());
    
    for (int i = 0; i < prices.size(); i++) {
        while (!time.empty() && prices[i] < prices[time.top()]) {
            int beginIdx = time.top();     // Java의 경우 그냥 pop하면 되지만, C++은 top 한 후 pop해줘야 함.
            time.pop();
            answer[beginIdx] = i - beginIdx;
        }
        time.push(i);
    }
    
    while (!time.empty()) {
        int beginIdx = time.top();     // Java의 경우 그냥 pop하면 되지만, C++은 top 한 후 pop해줘야 함.
        time.pop();
        answer[beginIdx] = prices.size() - beginIdx - 1;
    }
    return answer;
}
