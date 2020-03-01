//5점
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<int> shortest_dist(n+1,0); //각 노드의 최단경로 길이
    vector<bool> visited(n+1, false);
    visited[1] = true;
    
    queue<pair<int,int> > q;	//(node, 거리count)쌍
    for(auto e: edge){		//노드 1과 연결된 노드 queue에 저장
        int node = 0;
        if( e[0]==1 ){
            node = e[1];
        }else if( e[1]==1){
            node = e[0];
        }else{
            continue;
        }
        visited[node] = true;
        shortest_dist[node] =1;
        q.push(make_pair(node,1));
    }
    
    //BFS
    while(!q.empty()){
        pair<int, int> q_front = q.front();
        q.pop();
        for(int i=0; i<edge.size();i++){
            int node = 0;
            if(!visited[edge[i][1]] && edge[i][0] == q_front.first ){
                node = edge[i][1];  
            }else if(!visited[edge[i][0]] && edge[i][1] == q_front.first ){
                node = edge[i][0];
            }else{
                continue;
            }
            visited[node] = true;
            shortest_dist[node] = q_front.second +1;
            q.push(make_pair(node,shortest_dist[node]));
        }
        
    }
    
    sort(shortest_dist.begin(), shortest_dist.end(), greater<int>());
    
    int max = shortest_dist[0];
    for(int i=0; i<n;i++){
        if(shortest_dist[i]==max){
            answer++;
        }else{
            break;
        }
    }
    
    return answer;
}