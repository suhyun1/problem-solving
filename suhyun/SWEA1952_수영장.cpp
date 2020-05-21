#include<iostream>
using namespace std;

int prices[4];
int year_plan[13]; 
int min_cost;

void dfs(int month, int cost){
    if(month>12){
        if(cost > prices[3])	//1년 이용권
            cost = prices[3];
        if(min_cost > cost)
            min_cost = cost;
        return;
    }
    
   	if(year_plan[month] *prices[0] > prices[1]){	
        dfs(month+1, cost + prices[1]);	//한달 이용권
    }else{
        dfs(month+1, cost + prices[0]*year_plan[month]);	//1일 이용권
    }
    dfs(month+3, cost + prices[2]); //3달 이용권
}
int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;
    
	for(test_case = 1; test_case <= T; ++test_case)
	{
		for(int i=0; i<4;i++)
            cin >> prices[i];
        for(int i=1; i<13;i++)
            cin >> year_plan[i];
        min_cost = 3650;
        dfs(1,0);
		
        cout << "#" << test_case << " " << min_cost << endl;
	}
	return 0;
}