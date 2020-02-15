//8점
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>  min_heap;
    
    sort(jobs.begin(), jobs.end());
    
    int i = 0;
    int time = 0;
    int total_waiting_time = 0;
    while(i<jobs.size() || !min_heap.empty()){
        if(i<jobs.size() && time >= jobs[i][0]){
            min_heap.push(make_pair(jobs[i][1],jobs[i][0]));
            i++;
            continue;
        }
        if(!min_heap.empty()){
            time += min_heap.top().first;
            total_waiting_time += time - min_heap.top().second;
            min_heap.pop();
        }else{
            time = jobs[i][0];
        }
    }
    
    answer = total_waiting_time / jobs.size();
    return answer;
}