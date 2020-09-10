#include <algorithm>

using namespace std;

string solution(int n) {
    string answer = "";
    
    while(1){
        if(n == 0)   break;
        int mod = n % 3;
        n /= 3;
        if(mod == 0){
            answer += "4";
            n--;    
        }else
            answer += '0' + mod;
    }
    
    reverse(answer.begin(), answer.end());
    return answer;
}