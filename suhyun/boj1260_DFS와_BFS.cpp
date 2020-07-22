#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

vector<vector<int>> edge(1001);
bool visited[1001]= {false,};

void dfs(int start){
    visited[start] = true;
    cout << start << " ";

    for(int i=0; i<edge[start].size();i++){
        int next = edge[start][i];
        if(!visited[next]){
            dfs(next);
        }
    }
    
}

void bfs(int start){
    queue<int> q;
    q.push(start);
    
    visited[start] = true;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        for(int i=0; i<edge[cur].size();i++){
            int next = edge[cur][i];
            if(!visited[next]){
                visited[next] = true;
                q.push(next);
            }
        }
    }
    
}
int main()
{
    int N, M, V;
    cin >> N >> M >> V; //정점, 간선, 시작 정점
    
    
    int node1, node2;
    for(int i=0; i<M;i++){
        cin >> node1 >> node2;
        edge[node1].push_back(node2);
        edge[node2].push_back(node1);
        
    }
    
    //정렬
    for(int i=0; i<N+1;i++){
        sort(edge[i].begin(), edge[i].end());
    }

    dfs(V);
    cout << endl;
    memset(visited, false, sizeof(visited));
    
    bfs(V);

    return 0;
}
