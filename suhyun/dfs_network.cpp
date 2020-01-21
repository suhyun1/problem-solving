#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool visited[201];

void dfs (int index, vector<vector<int>> computers, int num){

    visited[index] = true;
    
    for(int i=0;i<num;i++){
        if(computers[index][i]==1 && !visited[i]){
            dfs(i, computers, num);
        }       
    }
    

}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0; i<n;i++){
        if(!visited[i]) {
            dfs(i, computers,n);
            answer ++;
        }   

    }
        
    return answer;
}

