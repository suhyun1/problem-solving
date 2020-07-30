#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 25
using namespace std;

int N, cnt;
int map[MAX][MAX];

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

void dfs(int x, int y){

    map[x][y] = 0;
    cnt++;
    

    for(int i=0; i<4; i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        
        if(nx>=0 && ny>=0 && nx<N && ny<N && map[nx][ny]==1)
            dfs(nx, ny);
    }
  
    
}

int main()
{
    
    cin >> N;
            
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            scanf("%1d", &map[i][j]);
    }

    vector<int> group;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(map[i][j]==1){
                cnt = 0;
                dfs(i, j);
                group.push_back(cnt);
            }
        }
    }
    
    sort(group.begin(), group.end());
    cout << group.size() <<endl;
    for(int i=0; i<group.size();i++)
        cout << group[i]<< endl;

    
    return 0;
}
