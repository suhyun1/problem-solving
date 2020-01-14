#include <string>
#include <vector>
#include <iostream>

using namespace std;

int matrix_path[101][101];
bool isPuddle[101][101];
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    matrix_path[1][0] = 1;
    
    for(int i=0;i<puddles.size();i++){
        isPuddle[puddles[i][1]][puddles[i][0]] = true;
        matrix_path[puddles[i][1]][puddles[i][0]] = 0;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!isPuddle[i][j])
                matrix_path[i][j] = (matrix_path[i-1][j] + matrix_path[i][j-1]) % 1000000007;
        }
    }
    
    answer = matrix_path[n][m];
    return answer;
}