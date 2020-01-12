#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    
    //가능한 숫자 123~987
    for(int i=123; i<=987;i++){
        
        string num = to_string(i);
        if(num[1]=='0' || num[2]=='0') continue;    //0 없음
        if(num[1]==num[0] || num[2]==num[1] || num[0]==num[2]) continue;    //세숫자 서로 다른값
        
        for(int j=0;j<baseball.size();j++){
                    
            string ask_num = to_string(baseball[j][0]);
            
            int ball = 0, strike = 0;
            
            if(num[0] == ask_num[0]) strike++;
            if(num[1] == ask_num[1]) strike++;
            if(num[2] == ask_num[2]) strike++;
            if(strike != baseball[j][1])    break;
            
            if(num[0] == ask_num[1] || num[0] == ask_num[2]) ball++;
            if(num[1] == ask_num[0] || num[1] == ask_num[2]) ball++;
            if(num[2] == ask_num[0] || num[2] == ask_num[1]) ball++;
            if(ball != baseball[j][2])    break;
            
            if(j == baseball.size()-1){ //모든 질문 통과한 경우
                answer++;
            }
          
            
        }
    }
    return answer;
}