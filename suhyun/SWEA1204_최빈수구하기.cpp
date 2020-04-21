#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

    	int tmp;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> tmp;
        int count[101] ={};
        for(int i=0; i<1000;i++){
            cin >> tmp;
            count[tmp]++;
        }
        
        int maxScore = 0;
        for(int i=0; i<101;i++){
            if(count[maxScore] <= count[i])
                maxScore = i;
        }
       	cout << "#" << test_case <<" "<< maxScore << endl;

	}
	return 0;
}