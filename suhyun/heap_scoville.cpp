#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue< int, vector<int>, greater<int> > pq;   //min heap
    for(int i=0;i<scoville.size();i++)
        pq.push(scoville[i]);
    
    if(pq.size()==1) return -1; //K이상 만들 수 없음
    
    int first, second, scoville_score;
    while(pq.top()<K && !pq.empty()){
        if(pq.size()==1) return -1;     //K이상 만들 수 없음
    
        first = pq.top();
        pq.pop();
        second = pq.top();
        pq.pop();
        scoville_score = first +(second*2);
        pq.push(scoville_score);
        answer++;
    }
    
    return answer;
}