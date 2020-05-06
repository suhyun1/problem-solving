#include <string>
#include <iostream>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int score[3]={0};
    int idx = -1;

    for(int i=0; i<dartResult.length();i++){
        if(dartResult[i] >= '0' && dartResult[i] <='9'){    //숫자
            idx++;
            if(dartResult[i+1]=='0') {//10
                score[idx] = 10;
                i++;
            }else{
                score[idx] = dartResult[i] - '0';
            }
        }else{
            if(dartResult[i]=='S'){ }
            else if(dartResult[i]=='D'){
                score[idx] = score[idx] * score[idx];
            }else if(dartResult[i]=='T'){
                score[idx] = score[idx] * score[idx] * score[idx];
            }else if(dartResult[i]=='*'){
                score[idx] *= 2;
                if(idx > 0)
                    score[idx-1] *= 2;
            }else if(dartResult[i]=='#'){
                score[idx] = -score[idx];
            }
        }
    }

    for(int i=0; i<3;i++){
        answer += score[i];
    }
    
    return answer;
}