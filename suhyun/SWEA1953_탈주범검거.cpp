#include<iostream>
#include<queue>
using namespace std;

int N, M, L; 
int map[50][50];
bool visited[50][50];
int dx[4] = {0,-1, 1, 0};
int dy[4] = {-1,0, 0, 1};

bool checkDirection(int dir, int pipe){
    if(dir == 0 && (pipe == 1 || pipe == 2 || pipe == 4 || pipe == 7 )) {	//상
		return true;
     }
    if(dir == 1 && (pipe == 1 || pipe == 3 || pipe == 6 || pipe == 7)) {	//좌
    	return true;
     }
    if(dir == 2 && (pipe == 1 || pipe == 3 || pipe == 4 || pipe == 5)) {	//우
       return true;
    }                 
   	if(dir == 3 &&(pipe == 1 || pipe == 2 || pipe ==5 || pipe == 6)) {	//하
         return true;
     }
    return false;
}

void bfs(int y, int x){
    int time = 1;
    queue<pair<int, int> >q;
    q.push(pair<int, int>(y, x));
    visited[y][x] = true;
    
    while(time < L){
        int size = q.size();
        for(int i=0; i<size;i++){
            int cur_y = q.front().first;
            int cur_x = q.front().second;
            q.pop();
            int pipe = map[cur_y][cur_x] ;
            
            for(int j=0;j<4;j++){
                if(checkDirection(j, pipe)) {	
                    int next_y = cur_y + dy[j];
                    int next_x = cur_x + dx[j];
                    if(next_y >=0 && next_y <N && next_x >=0 && next_x <M){
                        int next_pipe = map[next_y][next_x];
                        if(next_pipe == 0) continue;
                        if(checkDirection(3-j, next_pipe) && !visited[next_y][next_x]){
                            visited[next_y][next_x]=true;
                            q.push(pair<int, int>(next_y, next_x));
                        }
                    }
                }
            }
        }
       
        time++;
    }
    
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int  start_x, start_y;
        cin >> N >> M >> start_y >>  start_x >> L;
        for(int i=0 ;i<N;i++){
            for(int j=0;j<M;j++){
              	cin >> map[i][j];
                visited[i][j] = false;
            }
        }
        
        bfs(start_y, start_x);
		int visit_cnt = 0;
        for(int i=0 ;i<N;i++){
            for(int j=0;j<M;j++){
                if(visited[i][j])
                    visit_cnt++;
            }
        }
        cout << "#"<< test_case << " " << visit_cnt << endl;

	}
	return 0;
}