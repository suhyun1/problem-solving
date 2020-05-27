#include<iostream>
using namespace std;

int N, M;
int square(int depth){
    if(depth == 1)
        return N;
    return (N* square(depth-1));
}
int main(int argc, char** argv)
{
	int test_case;
	int T=10;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int case_num;
		cin >> case_num;a
        cin >> N >> M;
        cout << "#" << case_num << " " << square(M)<< endl;
	}
	return 0;
}