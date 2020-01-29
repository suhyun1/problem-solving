//4점
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> trucks;
    for(int i=0;i<truck_weights.size();i++){
        trucks.push(truck_weights[i]);
    }
    vector<pair<int,int> > truck_bridge;   //다리를 건너는 트럭 (무게, 지난 거리)쌍
    
    while(!trucks.empty() || !truck_bridge.empty()){
        answer++; //초 증가
        int sum = 0;
        
        for(auto t=truck_bridge.begin(); t!=truck_bridge.end();){
            if(t->second >=bridge_length){
                truck_bridge.erase(t);  
            }
            else {
                sum += t->first;
                t->second++;
                t++;
            }      
        }

        if(!trucks.empty() && sum+trucks.front() <= weight){ 
            int w = trucks.front();
            trucks.pop();
            truck_bridge.push_back(pair<int,int>(w,1));
            sum += w;
            
        }                        
        
    }
    
    return answer;
}