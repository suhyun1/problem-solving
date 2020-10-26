#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int INF = 100000000;
int N, E;
vector<pair<int, int> > edges[801];  

int dijkstra(int start, int end) {
    priority_queue<pair<int, int> > pq;
    vector<int> minDist(N + 1, INF);
    minDist[start] = 0;
    
    pq.push(pair<int,int>(0, start));
    while (!pq.empty()) {
        int cur = pq.top().second;
        int curDist = -pq.top().first;
        pq.pop();
        
        if (curDist > minDist[cur]) continue;
        
        for (auto e : edges[cur]) {
            int next = e.first;
            int nextDist = e.second;
            if (minDist[cur] + nextDist < minDist[next]) {
                minDist[next] = minDist[cur] + nextDist;
                pq.push(pair<int,int>(-nextDist, next));
            }
        }
    }
    
    return minDist[end]; 
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> E;
        
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back(pair<int, int>(b, c));
        edges[b].push_back(pair<int, int>(a, c));
    }
    
    int v1, v2;
    cin >> v1 >> v2;
    
    int path1 = dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, N);
    int path2 = dijkstra(1, v2) + dijkstra(v2, v1) + dijkstra(v1, N);
    if (path1 > INF || path2 > INF)
        cout << -1 <<endl;
    else if (path1 <= path2)
        cout << path1 << endl;
    else
        cout << path2 << endl;
        

    return 0;
}
