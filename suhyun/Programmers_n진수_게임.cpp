#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//number을 n진법으로 변환
string convert(int n, int number){
    if(number == 0)     return "0";
    
    string result = "";
    while(number>0){
        int mod = number % n;
        number /= n;
        if(mod >= 10)
            result += (char)('A'+mod-10);
        else 
            result += to_string(mod);
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