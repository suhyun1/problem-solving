#include <vector>
#include <string>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> baseball){
    vector<string> allcase;
    // 서로 다른 세 수로 이루어진 세자리 수.
    for(int i = 123; i <= 987; i++){
        string tmp{to_string(i)};
        if(tmp[0] == tmp[1] || tmp[0] == tmp[2] || tmp[1] == tmp[2] || tmp[0] == '0' || tmp[1] == '0' || tmp[2] == '0')
            continue;
        allcase.push_back(tmp);
    }
    // 스트라이크랑 볼 갯수 맞는 것 찾기.
    for(auto x : baseball){
        string tmp = to_string(x[0]);       // 123, 356 이런거 tmp에 넣기.
        for(int i = allcase.size() - 1; i >= 0; i--){
            int strike = 0, ball = 0;
            for(int j = 0; j < 3; j++){
                if(tmp[j] == allcase[i][j])     // strike (숫자와 자리 모두 맞음)
                    strike++;
                if(tmp[j] == allcase[i][(j+1)%3] || tmp[j] == allcase[i][(j+2)%3])      // ball (숫자만 맞음)
                    ball++;
            }
            if(strike != x[1] || ball != x[2])
                allcase.erase(allcase.begin() + i);     // 스트라이크나 볼의 수 다르면 allcase에서 제거
        }
    }
    return allcase.size();      // allcase의 size가 맞는 것들의 갯수.
}

int main() {
    vector<vector<int>> baseball{{123,1,1},{356,1,0},{327,2,0},{489,0,1}};
    int answer = solution(baseball);
    cout << "The answer is : "<< answer << endl;
    return 0;
}

