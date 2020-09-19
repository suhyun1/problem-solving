#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    
    int triangle[1001][1001];
    int depth = n;
    int start_x = -1, start_y = 0;
    int number = 1;
    
    while(1){
        for(int i=0; i<depth; i++){
            triangle[++start_x][start_y] = number++;
        }
        if(depth == 1) break;
        depth--;
        
        for(int i=0; i<depth; i++){
            triangle[start_x][++start_y] = number++;
        }
        if(depth == 1) break;
        depth--;
        
        for(int i=0; i<depth; i++){
            triangle[--start_x][--start_y] = number++;
        }
        if(depth == 1) break;
        depth--;
        
    }
    
    for(int i=0; i<n ;i++){
        for(int j=0; j<n ;j++)
            if(triangle[i][j] != 0) answer.push_back(triangle[i][j]);
    }
    return answer;
}