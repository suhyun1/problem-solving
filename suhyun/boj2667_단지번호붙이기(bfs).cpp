#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 25
using namespace std;

int N, cnt;
char map[MAX][MAX];

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

void bfs(int x, int y){
    queue<pair<int,int> > q;
    
    map[x][y] = '0';
    q.push(pair<int,int>(x,y));
    cnt++;
    
    while(!q.empty()){
        
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++)
        {
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            
            if(nx>=0 && ny>=0 && nx<N && ny<N && map[nx][ny]=='1'){
                
                map[nx][ny] = '0';
                q.push(pair<int,int>(nx,ny));
                cnt++;
            }
               
        }
    }
  
}

int main()
{
    
    cin >> N;
            
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cin >> map[i][j];
    }

    vector<int> group;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(map[i][j]=='1'){
                cnt = 0;
                bfs(i, j);
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
