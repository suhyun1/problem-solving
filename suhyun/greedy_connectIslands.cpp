//7점
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent(101);

bool cmp(vector<int> &a, vector<int> &b ){
    return a[2] <  b[2];
}
int getParent(int island){
    if(parent[island] == island){
        return island;
    }else{
        return getParent(parent[island]);
    }
}
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    sort(costs.begin(), costs.end(), cmp); //cost작은 것부터
    
    for(int i=0; i<n;i++){
        parent[i] = i;
    }
    
    //모든 edge 검사
    for(int i=0; i<costs.size();i++){
        int root1 = getParent(costs[i][0]);
        int root2 = getParent(costs[i][1]);
        
        if(root1 != root2){ // 다른집합이면
            parent[root1] = root2;  //두 집합 하나로 합침
            answer += costs[i][2];
        }
    }
    
    return answer;
}