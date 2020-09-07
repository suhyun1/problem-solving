#include <string>
#include <vector>
#include <algorithm>
using namespace std;

char map[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };

//number을 n진법으로 변환
string convert(int n, int number){
    if(number == 0)     return "0";
    
    string result = "";
    while(number>0){
        int mod = number % n;
        result += map[mod];
        number /= n;
    }
    
    reverse(result.begin(), result.end());
    return result;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string seq = "";    //전체순서
    int number = 0;
    while(1){
        if(t*m <= seq.size())   break;
        seq += convert(n, number);
        number++;
    }
    for(int i=0; i<t; i++){
        answer.push_back(seq[i*m+p-1]);
    }
    return answer;
}