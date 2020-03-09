//7점
#include <string>
#include <vector>

using namespace std;

int solution(int K, vector<vector<int>> travel) {
    int answer = 0;
    int DP[101][100001];    //DP[구간][현재까지 이동한 시간] : 현재까지 모금액
    
    DP[0][travel[0][0]] = travel[0][1];
    DP[0][travel[0][2]] = travel[0][3];
    
    for(int i=1; i<travel.size();i++){
        int walk_time = travel[i][0];
        int walk_money = travel[i][1];
        int ride_time = travel[i][2];
        int ride_money = travel[i][3];
        
        for(int j=0; j<=K; j++){
            if(DP[i-1][j]==0)  continue;
            if(j+walk_time <= K){
                DP[i][j+walk_time] = max(DP[i][j+walk_time], DP[i-1][j]+walk_money);
            }
            if(j+ride_time <= K){
                DP[i][j+ride_time] = max(DP[i][j+ride_time], DP[i-1][j]+ride_money);
            }
            int max_money = max(DP[i][j+walk_time], DP[i][j+ride_time]);
            answer = max(answer, max_money);
        }
    }
    
    return answer;
}