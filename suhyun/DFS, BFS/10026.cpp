/*10026 적록색약: RGB그림에서 적록색약인 사람과 그렇지 않은 사람 관점에서 구역의 수 구하기*/
#include <iostream>
using namespace std;

int N;
bool visited[101][101];
char pic[101][101];

int x0[4] = {-1, 1, 0, 0};
int y0[4] = {0, 0, -1, 1};

void DFS(int x, int y){
	visited[x][y]  = true;
	
	//상하좌우로 현재 색과 같은지 탐색 
	for(int i=0;i<4;i++){
		int dx = x+x0[i];
		int dy = y+y0[i];
		if(dx>=0&& dx<N && dy>=0 && dy<N){
			if(pic[x][y]==pic[dx][dy] &&!visited[dx][dy])	 
				DFS(dx,dy);
		}	
	}
	
}

int main(){
	
	int size;
	cin >> size;
	
	N = size;

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> pic[i][j];
			visited[i][j]=false;
		}
	}
		
	//적록색약 아닌 사람 관점의 구역 탐색	
	int cnt=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(!visited[i][j]){
				DFS(i,j);
				cnt++;	
			}
		}	
	}
	cout << cnt <<" ";
	
	//R->G로 변경 및 visited배열 초기화
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++){
			visited[i][j] =false;
			if(pic[i][j]=='R') pic[i][j]='G';
		}
			
 
	//적록색약인 사람 관점의 구역 탐색	
	cnt=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(!visited[i][j]){
				DFS(i,j);
				cnt++;	
			}
		}	
	}
		
	cout << cnt;
			
}
