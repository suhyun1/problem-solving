//8
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(int a, int b) 
{ 
    return (a < b); 
} 

int solution(vector<int> left, vector<int> right) {
    int answer = 0;
    int size = left.size();
    
    vector<vector<int>> DP(size+1, vector<int>(size+1));
    
    for(int i=0; i<=size; i++){
        DP[0][i] = -1;
    }
    
    for(int i=1; i<=size; i++){
        for(int j =1; j<=size; j++){

            if(left[i-1] > right[j-1]){
                DP[i][j] = max({DP[i-1][j-1], DP[i-1][j], DP[i][j-1]+right[j-1]}, cmp);
            }else{
                DP[i][j] = max(DP[i-1][j-1], DP[i-1][j]);
            }
        }
    }
        
    answer = DP[size][size];
    return answer;
}