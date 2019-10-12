/*4179 불!: 1초에 불이 네방향으로 확산되고 지훈 한칸 움직일 때, 미로 탈출하는 가장 빠른 탈출시간*/
#include <iostream> 
#include <queue>
#define MAX 1001
using namespace std;

bool visited[MAX][MAX];
char map[MAX][MAX];

int R, C;
queue <pair<int, int> > fire, jh;
int x0[4] = {-1, 1, 0, 0};
int y0[4] = {0, 0, -1, 1};

int moveBFS(){
	
	int sec=0;
	
	while(!jh.empty()){
		int size = fire.size();
		for(int i=0;i<size;i++){ 	//모든 불 위치마다 수행 
			
			int y = fire.front().first;
			int x = fire.front().second;
			fire.pop();
			
			for(int j=0;j<4;j++){	// 상하좌우 확산 
				int dx = x+x0[j];
				int dy = y+y0[j];
				if(dx>=0&& dx<C && dy>=0 && dy<R && (map[dy][dx]=='.'||map[dy][dx]=='J')){	
				//if문 뒤의 조건에서 map[dy][dx]!='#' 만 넣었는데, 오류났음 왜?? 
					map[dy][dx]='F';
					fire.push(pair<int,int>(dy, dx));
				}
			}
		}
			
			
		size = jh.size();
		for(int i=0;i<size;i++){ 	
			int y = jh.front().first;
			int x = jh.front().second;
			jh.pop();
			
			for(int j=0;j<4;j++){	// 상하좌우로 이동시도 
				int dx = x+x0[j];
				int dy = y+y0[j];
		
				//탈출 성공 조건 
				if((dx<0 || dx>=C || dy<0 || dy>=R)){	
					return sec+1;
				}
				if(!visited[dy][dx]&&map[dy][dx]=='.'){	//방문한적 없고, 지나갈 수 있는 길이면  
					jh.push(pair<int,int>(dy, dx));
					visited[dy][dx] = true;
					map[dy][dx]='J';
				}
				
			}
		}
		sec++;
	}
	return -1;
}

int main(){
	
	cin >> R >> C;
	
	for(int i=0; i<R;i++){
		for(int j=0;j<C;j++){
			cin >> map[i][j];
			visited[i][j] = false;
			
			if(map[i][j]=='J'){
				jh.push(pair<int,int>(i,j));
				visited[i][j] = true;
			}
			else if (map[i][j]=='F'){
				fire.push(pair<int,int>(i,j));
			}
		}
	}
	
	int result = moveBFS();
	if(result == -1)
		cout << "IMPOSSIBLE";
	else
		cout << result; 
			
}
