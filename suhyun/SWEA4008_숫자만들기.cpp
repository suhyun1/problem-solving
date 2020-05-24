#include<iostream>
#include <algorithm>
using namespace std;

int N, min_res, max_res;
int num[12];
int op[4]; 

void dfs(int depth, int result){
    if(depth == N-1){
        min_res = min(result, min_res);
        max_res = max(result, max_res);
        return;
    }
    if(op[0] > 0){
        op[0]--;
        dfs(depth+1, result+num[depth+1]);
        op[0]++;
    }
    if(op[1] > 0){
        op[1]--;
        dfs(depth+1, result-num[depth+1]);
        op[1]++;
    }
    if(op[2] > 0){
        op[2]--;
        dfs(depth+1, result*num[depth+1]);
        op[2]++;
    }
    if(op[3] > 0){
        op[3]--;
        dfs(depth+1, result/num[depth+1]);
        op[3]++;
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
        for(int i=0; i<4;i++){
        	cin >> op[i];
        }
        for(int i=0;i<N;i++)
            cin >> num[i];
        
        min_res = 100000000;
        max_res = -100000000;
        dfs(0,num[0]);
        
        cout << "#" << test_case << " " << max_res-min_res << endl;

	}
	return 0;
}