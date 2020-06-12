#include<iostream>
#include<stack>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T=10;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int len;
        string secret;
        cin  >> len >>  secret;
       	stack<char> s;
        for(int i=0;i<len;i++){
            if(!s.empty() && s.top()==secret[i])
                s.pop();
            else
            	s.push(secret[i]);
        }
        
        string tmp="";
        while(!s.empty()){
            tmp += s.top() ;
            s.pop();
        }
        cout << "#" <<test_case << " ";
        for(int i=tmp.length()-1; i>=0; i--)
            cout << tmp[i];
		cout << endl;
	}
	return 0;
}