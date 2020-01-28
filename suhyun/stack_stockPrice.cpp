//4점
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    
    stack<int> time;
    int size = prices.size();
    vector<int> answer(size);
    
    for(int i=0;i<size;i++){
        while(!time.empty() && prices[time.top()]>prices[i]){
            answer[time.top()]= i-time.top();
            time.pop();
        }
        time.push(i);
    }
    
    
    while(!time.empty()){
        int top = time.top();
        time.pop();
        answer[top] = size - top -1;
    }
    
    return answer;
}