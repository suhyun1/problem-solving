#include<iostream>
using namespace std;

bool visited[100];
void dfs(int idx, int route1[], int route2[]){
    visited[idx] = true;
    if(idx ==99)
        return;
    
    if(route1[idx]!=0)
        dfs(route1[idx], route1, route2);
    if(route2[idx]!=0)
        dfs(route2[idx], route1, route2);
    
    return;
}
int main(int argc, char** argv)
{
	int test_case;
	int T=10;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int route1[100]={0,};
        int route2[100]={0,};
        int test_num, route_pair;
        int start, end;
        cin >> test_num >> route_pair;
        for(int i=0; i<route_pair ;i++){
            cin >> start >> end;
            if(route1[start]==0){
               route1[start]= end;
            }
            else{
                route2[start]= end;
            }
                
        }

        for(int i=0; i<100;i++)
            visited[i] = false;
        dfs(0,route1, route2);
        cout << "#" << test_num << " " << visited[99] << endl;
            

	}
	return 0;
}