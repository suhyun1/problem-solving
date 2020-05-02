#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N, K;
        cin >> N >> K;
        vector<char> numbers(N);
        for(int i=0; i<N;i++){
            cin>> numbers[i];
        }
        set<string, greater<string> > num_set;	//생성 가능한 수 set
        int len = N/4; //한변 길이
        for(int k=0; k<len;k++){
            for(int i=0; i<4;i++){
                string tmp ="";
                for(int j=0; j<len; j++){
                    tmp += numbers[i*len +j];
                }
                num_set.insert(tmp);
            }
            char tmp = numbers[0];
            numbers.erase(numbers.begin()); 
            numbers.push_back(tmp);
        }
        
        set<string>::iterator it = num_set.begin() ;
        std::advance(it, K-1);
        string answer = *it;
        
        //16진수 -> 10진수
        int tmp[8];
        for(int i=0; i<answer.length();i++){
            if(answer[i] >= 'A' && answer[i] <='F')
            	tmp[i] = 10 + answer[i] -'A';
            else
                tmp[i] = answer[i] -'0';
        }
        int dec_ans=0;
        for(int i = answer.length()-1; i>=0; i--){
            dec_ans += (pow(16,answer.length()-i-1) *tmp[i] );	//pow:제곱
        }
        cout <<"#" << test_case <<" "<<  dec_ans << endl;

	}
	return 0;
}