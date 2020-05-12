#include<iostream>
#include <queue>
#define MAX 8
using namespace std;

int map[MAX][MAX];
int visited[MAX][MAX];
int N, M;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs( queue <pair<int, int> > virus,  queue <pair<int, int> > samsung){
    int time = 0;
    while(!samsung.empty()|| !virus.empty()){
        //불 확산
        int v_size = virus.size();
        for(int i=0; i<v_size;i++){
            int cur_x = virus.front().first;
            int cur_y = virus.front().second;
            virus.pop();
            for(int j=0;j<4;j++){
                int x = cur_x + dx[j];
                int y = cur_y + dy[j];
                if(x>=0 && x<N && y>=0 && y<M && (map[x][y] == 0 || map[x][y] == 3)){
                    virus.push(pair<int,int>(x,y));
                    map[x][y] = 2;
                }
            }
        }
        //삼성이 이동
        int s_size = samsung.size();
        for(int i=0; i<s_size;i++){
            int cur_x = samsung.front().first;
            int cur_y = samsung.front().second;
            samsung.pop();
            
            for(int j=0;j<4;j++){
                int x = cur_x + dx[j];
                int y = cur_y + dy[j];
                if(x<0 || y<0 || x>=N || y>=M)//탈출 
                    return time+1;
                if( !visited[x][y] && map[x][y] == 0){
                    samsung.push(pair<int,int>(x,y));
                    visited[x][y] = true;
                    map[x][y] = 3;
                }
            }
        }
        
        time ++;
    }
    bool zombieExist = true;
    for(int i=0; i<N;i++){
        for(int j=0;j<M;j++)
            if(map[i][j] ==3)
                zombieExist = false;
    }
    
    if(zombieExist)
        return -2;	
    else
        return -1;	//cannot escape
    
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> N >> M;
        queue <pair<int, int> > virus, samsung;
        for(int i=0; i<N;i++){
            for(int j=0; j<M;j++){
                cin >> map[i][j];
                visited[i][j] = false;
                if(map[i][j] == 2){
                    virus.push(pair<int,int>(i, j));
                }
                else if(map[i][j] ==3){
                    samsung.push(pair<int,int>(i, j));
                    visited[i][j] = true;
                }
            }
        }
        int answer = bfs(virus, samsung);
        
        if(answer == -1)
            cout << "#" << test_case << " CANNOT ESCAPE"   << endl;
        else if (answer == -2)
            cout <<"#" << test_case <<  " ZOMBIE" << endl;
        else
            cout <<"#" << test_case <<  " " << answer  << endl;
	}
	return 0;
}