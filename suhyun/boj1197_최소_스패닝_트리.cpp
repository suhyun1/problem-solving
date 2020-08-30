#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//1. cost 순으로 간선 정렬
//2. 차례대로 간선의 두 정점이 속한 부모 확인 
//3. 부모 같지 않으면 부모 중 더 작은 정점으로 변경(unionParent)하고 cost 더함
//부모가 같으면 사이클이 발생하는 것 => 이 간선은 버림

int parent[10001];

int getParent(int node){
    if(parent[node] == node)
        return node;
    else
        return parent[node]= getParent(parent[node]);
}

void unionParent(pair<int, int> edge){
    int p1 = getParent(edge.first);
    int p2 = getParent(edge.second);
    if(p1 > p2)
        parent[p1] = p2;
    else 
        parent[p2] = p1;
    
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
        
    int V, E;
    cin >> V >> E ;
    vector<pair<int, pair<int, int> > >  edges;
    for(int i=0; i<E;i++){
        int A, B, C;
        cin >> A >> B >> C;
        edges.push_back(make_pair(C, make_pair(A, B)));
    }
    sort(edges.begin(), edges.end());
    
    for(int i=1; i<=V; i++)
        parent[i] = i;
        
    long long sum = 0;
    for(int i=0;i<edges.size();i++){
        if(getParent(edges[i].second.first)!=getParent(edges[i].second.second)){
            sum += edges[i].first;
            unionParent(edges[i].second);
        }
    }
    cout << sum <<endl;
    
    
}