//3점
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    deque<int> dq;
    for(int i=0;i<operations.size();i++){
        if(operations[i][0] =='I' ){
            dq.push_back(stoi(operations[i].substr(2)));
            sort(dq.begin(), dq.end());
        }else if(operations[i]=="D 1" && !dq.empty()){ //최댓값 삭제
            dq.pop_back();          
        }else if(operations[i]=="D -1"&& !dq.empty()){//최솟값 삭제
            dq.pop_front();
        }
    }
    
    if(dq.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }else{
        answer.push_back(dq.back());
        answer.push_back(dq.front());
    }
    
    return answer;
}