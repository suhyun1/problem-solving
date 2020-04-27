#include<iostream>
#include<string>

using namespace std;
 
int countMatching(string s, string p){
    int cnt = 0;
    int n = s.size(), m = p.size();
     
    for(int i=0; i<=n-m; i++){
        int j;
        for(j=0; j<m;j++){
            if(p[j] != s[i+j])
                break;
        }
        if(j==m)
          cnt++;
    }
     
    return cnt;
             
}
int main(int argc, char** argv)
{
    int test_case;
    int T=10;
 
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int test_num;
        cin >> test_num;
 
        string pattern, sentence;
        cin >> pattern >> sentence;
 
        cout << "#"<< test_case << " "<< countMatching(sentence,pattern) << endl;
 
    }
    return 0;
}