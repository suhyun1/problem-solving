/*5247 불: 매초마다 불이 동서남북방향으로 확산되고 상근 한칸 움직일 때, 빌딩 탈출하는 가장 빠른 탈출시간*/
#include <iostream> 
#include <queue>
#define MAX 1001
using namespace std;

bool visited[MAX][MAX];
char map[MAX][MAX];

int H, W;

int x0[4] = {-1, 1, 0, 0};
int y0[4] = {0, 0, -1, 1};

int moveBFS(queue <pair<int, int> > sg, queue <pair<int, int> > fire){
	
	int sec=0;
	
	while(!sg.empty()){
		int size = fire.size();
		for(int i=0;i<size;i++){ 	//모든 불 위치마다 수행 
			
			int y = fire.front().first;
			int x = fire.front().second;
			fire.pop();
			
			for(int j=0;j<4;j++){	// 상하좌우 확산 
				int dx = x+x0[j];
				int dy = y+y0[j];
				if(dx>=0&& dx<W && dy>=0 && dy<H && (map[dy][dx]=='.'||map[dy][dx]=='@')){	
					map[dy][dx]='*';
					fire.push(pair<int,int>(dy, dx));
				}
			}
		}
			
			
		size = sg.size();
		for(int i=0;i<size;i++){ 	
			int y = sg.front().first;
			int x = sg.front().second;
			sg.pop();
			
			for(int j=0;j<4;j++){	// 상하좌우로 이동시도 
				int dx = x+x0[j];
				int dy = y+y0[j];
		
				//탈출 성공 조건 
				if(dx<0 || dx>=W || dy<0 || dy>=H){	
					return sec+1;
				}
				if(!visited[dy][dx]&&map[dy][dx]=='.'){	//방문한적 없고, 지나갈 수 있는 길이면  
					sg.push(pair<int,int>(dy, dx));
					visited[dy][dx] = true;
					map[dy][dx]='@';
				}
				
			}
		}
		sec++;
	}
	return -1;
}

int main(){
	
	int testCase;
	cin >> testCase;
	for(int k=0;k<testCase;k++) {
		cin >> W >> H;
	
		queue <pair<int, int> > fire, sg;
		for(int i=0; i<H;i++){
			for(int j=0;j<W;j++){
				cin >> map[i][j];
				visited[i][j] = false;
				
				if(map[i][j]=='@'){
					sg.push(pair<int,int>(i,j));
					visited[i][j] = true;
				}
				else if (map[i][j]=='*'){
					fire.push(pair<int,int>(i,j));
				}
			}
		}
		
		int result = moveBFS(sg, fire);
		if(result == -1)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << result<<endl;	
			
		
	}
	 
			
}
