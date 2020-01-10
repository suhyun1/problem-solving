# 숫자야구

## 아이디어

+ 우선 서로 다른 세 수로 이루어진 세자리 수의 경우를 구하여 벡터 allcase에 넣었다.
+ auto 사용법을 공부하여 적용해 보았다.
+ allcase를 직접 하나하나 비교하여 strike와 ball의 갯수를 구하고 주어진 테스트 케이스와 비교. <br>


## 구현하기 
+ 우선 서로 다른 세 수로 이루어진 세자리 수의 경우를 구하여 벡터 allcase에 넣었다.
~~~cpp
    vector<string> allcase;
    // 서로 다른 세 수로 이루어진 세자리 수.
    for(int i = 123; i <= 987; i++){
        string tmp{to_string(i)};
        if(tmp[0] == tmp[1] || tmp[0] == tmp[2] || tmp[1] == tmp[2] || tmp[0] == '0' || tmp[1] == '0' || tmp[2] == '0')
            continue;
        allcase.push_back(tmp);
    }
~~~

+ allcase를 직접 하나하나 비교하여 strike와 ball의 갯수를 구하고 주어진 테스트 케이스와 비교.
~~~cpp
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
~~~

+ 전체 코드
~~~cpp
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
~~~

+ 의문점
~~~cpp
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
        for(int i = 0; i <= allcase.size() - 1; i++){
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
~~~
- 이 코드는 왜 47개라는 답이 나올까?