#include<iostream>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T=10;
    int arr[100][100];
    int test_num;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> test_num;
        for(int i=0; i<100;i++)
            for(int j=0;j<100;j++)
                cin >> arr[i][j];
        
        int max_sum = 0;
        int cnt = 0;
        //가로
        for(int i=0; i<100;i++){
            int sum = 0;
            for(int j=0;j<100;j++){
                sum += arr[i][j];
            }
            max_sum = max(sum, max_sum);
        }
        //세로
         for(int i=0; i<100;i++){
            int sum = 0;
            for(int j=0;j<100;j++){
                sum += arr[j][i];
            }
            max_sum = max(sum, max_sum);
        }
        //대각선
        int sum = 0;
        for(int i=0; i<100;i++)
            sum += arr[i][i];
        max_sum = max(sum, max_sum);
        sum = 0;
        for(int i=0; i<100;i++)
            sum += arr[i][100-i];
        max_sum = max(sum, max_sum);
		cout << "#" << test_case << " " << max_sum << endl;
	}
	return 0;
}