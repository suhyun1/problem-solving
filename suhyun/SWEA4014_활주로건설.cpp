#include<iostream>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int N, X;
        cin >> N>> X;
        
        int map[21][21];
        for(int i=0; i<N;i++){
            for(int j=0;j<N;j++){
                cin >> map[i][j];
            }
        }
        
        int possibleCount = 0;
        //가로줄 검사
        for(int i=0;i<N;i++){
            bool possible = true;	//건설 가능 여부
            bool visit[20] = {false,}; //방문(경사로 설치) => 1 
            
            for(int j=1;j<N;j++){
                int cur = map[i][j];
                int prev =  map[i][j-1];
                if(cur == prev)
                    continue;
                
                if(abs(cur - prev) >1){
                    possible = false;
                    break;
                }
                
                if(cur > prev) {//오른쪽이 큰 경우 (왼쪽 설치)
                    for(int k=j-2; k>=j-X ;k--){	//경사로길이(X)만큼 확인
                        if(k < 0 || map[i][k] !=prev || visit[k]  ){
                            possible = false;
                            break;
                        }
                    }
                    if(possible){
                        for(int k=j-1; k>=j-X ;k--)
                            visit[k] = true;
                    }
                }
                else if(cur < prev) {//왼쪽이 큰 경우(오른쪽 설치)
                    for(int k=j+1; k<j+X ;k++){	//경사로길이(X)만큼 확인
                        if(k >=N|| map[i][k] !=cur || visit[k] ){
                            possible = false;
                            break;
                        }
                    }
                    if(possible){
                        for(int k=j; k<j+X ;k++)
                            visit[k] = true;
                    }
                }
            }
            if(possible)
            	possibleCount++;
        }
        
        //세로줄 검사
        for(int i=0;i<N;i++){
            bool possible = true;	
            bool visit[20] = {false,}; 
            
            for(int j=1;j<N;j++){
                int cur = map[j][i];
                int prev =  map[j-1][i];
                if(cur == prev)
                    continue;
                
                if(abs(cur - prev) >1){
                    possible = false;
                    break;
                }
                
                if(cur > prev) {//오른쪽이 큰 경우 (왼쪽 설치)
                    for(int k=j-2; k>=j-X ;k--){	//경사로길이(X)만큼 확인
                        if(k < 0 || map[k][i] !=prev || visit[k]  ){
                            possible = false;
                            break;
                        }
                    }
                    if(possible){
                        for(int k=j-1; k>=j-X ;k--)
                            visit[k] = true;
                    }
                }
                else if(cur < prev) {//왼쪽이 큰 경우(오른쪽 설치)
                    for(int k=j+1; k<j+X ;k++){	//경사로길이(X)만큼 확인
                        if(k >=N|| map[k][i] !=cur || visit[k] ){
                            possible = false;
                            break;
                        }
                    }
                    if(possible){
                        for(int k=j; k<j+X ;k++)
                            visit[k] = true;
                    }
                }
            }
            if(possible)
            	possibleCount++;
        }
        cout << "#" << test_case << " " << possibleCount << endl;

	}
	return 0;
}