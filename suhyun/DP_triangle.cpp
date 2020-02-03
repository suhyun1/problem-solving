//3점
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int size = (triangle.size() * triangle.size()+1)/2;
    int sum[500][502];
  
    //초기화
    for(int i=0; i<triangle.size();i++){
        sum[i][0] = 0;
        sum[i][i+2]=0;
    }
    sum[0][1] = triangle[0][0];
    
    //DP
    for(int i=1;i<triangle.size();i++){
        for(int j=1;j<=i+1;j++){
            int max = sum[i-1][j] >  sum[i-1][j-1] ? sum[i-1][j] : sum[i-1][j-1];
            sum[i][j] = max + triangle[i][j-1];
        }
    }
    
    //맨 아랫줄에서 가장 큰 수
    for(int i=0; i<triangle.size()+1 ;i++){
        if( answer < sum[triangle.size()-1][i] )
            answer = sum[triangle.size()-1][i];
    }
    
    return answer;
}