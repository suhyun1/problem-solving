#include<iostream>
#include<queue>
using namespace std;


int main(int argc, char** argv)
{
	int test_case;
	int T=10;
	int num;
    queue<int> q;
    cin.tie(NULL);
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int test_num;
        cin>> test_num;
        
        for(int i=0;i<8;i++){
            cin >> num;
            q.push(num);
        }
        int tmp;
        int cnt=1;
        while(1){
            tmp = q.front()-cnt;
            q.pop();
            if(tmp <= 0){
                q.push(0);
                break;
            }
            q.push(tmp);
           	if(cnt == 5) 
                cnt = 1;
            else 
                cnt++;
        }
        
        cout <<"#" <<test_num << " ";
		for(int i=0;i<8;i++){
            cout << q.front() <<" ";
            q.pop();
        }
        cout << endl;
	}
	return 0;
}