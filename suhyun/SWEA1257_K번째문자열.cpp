#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int K;
        string pattern;
        vector<string> sub;
		cin >> K >> pattern;
        int len = pattern.length();
		for(int i=0; i<len;i++){
            for(int j=i; j<len;j++){
                sub.push_back(pattern.substr(i, j-i+1));
            }
        }
        sort(sub.begin(), sub.end());
        
        int cnt = 0;
        string prev = "";
        bool find = false;
        cout << "#" << test_case << " ";
        for(int i=0; i<sub.size();i++){
            if(prev == sub[i]){
                prev = sub[i];
                continue;
            }
            prev = sub[i];
            cnt++;
            if(cnt == K){
                cout << sub[i] << endl;
                find = true;
				break;
            }
        }
        if(!find)
            cout << "none" << endl;
        
	}
	return 0;
}