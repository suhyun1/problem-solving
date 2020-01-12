#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    queue<pair<int,int>> seq;   //<중요도,priorities의 인덱스> 쌍
    priority_queue<int> important;  //중요도 순 저장
    
    for(int i=0;i<priorities.size();i++){
        seq.push(make_pair(priorities[i],i));
        important.push(priorities[i]);
    }
    
    while(!seq.empty()){
        if(important.top()==seq.front().first){ //출력
            answer++;
            if(seq.front().second == location)  break;
            seq.pop();
            important.pop();      
        }
        else{
            seq.push(make_pair(seq.front().first, seq.front().second));
            seq.pop();
        }
    }
    
    return answer;
}