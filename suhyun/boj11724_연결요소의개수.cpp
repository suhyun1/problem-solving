#include <iostream>
#include <vector>
using namespace std;     

int visited[1001] = {false,};
vector<int> nodes[1001];

void dfs(int v){
    visited[v] = true;
    for(int i = 0; i < nodes[v].size(); i++){
        if(!visited[nodes[v][i]]){
            dfs(nodes[v][i]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    int node1, node2;
    for(int i = 0; i < M; i++){
        cin >> node1 >> node2;
        nodes[node1].push_back(node2);
        nodes[node2].push_back(node1);
    }
    
    int connect_count = 0;
    for(int i = 1; i <= N; i++){
        if(!visited[i]){
            connect_count++;
            dfs(i);
        }
    }
    cout << connect_count << endl;
    return 0;
}
