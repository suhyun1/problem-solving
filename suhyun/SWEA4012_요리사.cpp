#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int table[16][16];
bool visited[16];
int N;
int min_diff;

int getDiff(vector<int> A, vector<int> B){
    int sum1 = 0;
    int sum2 = 0;
    for(int i=0; i<N/2; i++){	//S(i,j)+S(j,i)
        for(int j=0; j<N/2;j++){
            if(i!=j){
           		sum1 += table[A[i]][A[j]];
				sum2 += table[B[i]][B[j]];
            }
        }
    }
    return abs(sum1- sum2);
}

void dfs(int depth, int len){
    if(len == N/2){	//재료 가짓수 반으로 나눈 경우
        vector <int> food_A, food_B;
        for(int i=0; i<N;i++){
            if(visited[i]){
                food_A.push_back(i);
            }else{
                food_B.push_back(i);
            }
        }
        min_diff = min(min_diff, getDiff(food_A, food_B));
        return;
    }
    
    for(int i=depth; i<N;i++){
        if(!visited[i]){
            visited[i] = true;
            dfs(i+1,len+1);
            visited[i] = false;
        }
    }
    
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
       	cin >> N;
        for(int i=0; i<N;i++){
            for(int j=0;j<N;j++)
                cin >> table[i][j];
        }
        min_diff = 160000;
        dfs(0,0);
		cout << "#" << test_case << " " << min_diff << endl;
	}
	return 0;
}