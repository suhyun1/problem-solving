#include <iostream>
#include <vector>
using namespace std;

int N;
int matrix[1001][1001];
int degree[1001] = {0};
vector<int> answer;

void dfs(int cur){ 
    for(int i=1; i<=N;i++){
        while(matrix[cur][i]>0){
            matrix[cur][i]--;
            matrix[i][cur]--;
            bfs(i);
        }
        
    }
    answer.push_back(cur);
}

int main()
{   
    cin >> N;
    //차수가 홀수인 정점이 없으면 오일러서킷 존재함
    bool flag = false;  //홀수가 있으면 true
    for(int i=1; i<=N;i++){
        for(int j=1; j<=N;j++){
            cin >> matrix[i][j];
            degree[i] += matrix[i][j];
        }
        
        if(degree[i]%2!=0)
            flag = true;
    }
    
    if(!flag){
        dfs(1);
        for(int i=0; i<answer.size();i++)
            cout <<answer[i] <<" ";
    }else{
        cout << "-1" <<endl;
    }
    
    return 0;
}
