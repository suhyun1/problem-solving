#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 최소 스패닝 트리 (프림 알고리즘)

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int N, M; //컴퓨터 수(v), 선의 수(e)
    cin >> N;
    cin >> M;
    vector<vector<pair<int, int> > > edges(N+1);  //idx: 정점, (cost, dest) 쌍
    priority_queue<pair<int, int> , vector<pair<int, int> >,greater<>> pq;
    bool visited[1001]= {false};
    
    for(int i=0; i<M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back(make_pair(c, b));
        edges[b].push_back(make_pair(c, a));
    }
    
    int sum = 0;
    int cur = 1;
    for(int i=0; i<N; i++){
        visited[cur] = true;
        
        for (auto e: edges[cur]) {
            if (!visited[e.second]) {
                pq.push(make_pair(e.first, e.second));
            }
        }
        while(!pq.empty()){
            auto min = pq.top();
            pq.pop();
            if(!visited[min.second]){
                sum += min.first;
                cur = min.second;
                break;
            }
        }
    
    }
    cout << sum <<endl;
    
}