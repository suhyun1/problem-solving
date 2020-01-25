#include <string>
#include <stack>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    
    stack<char> stick;
    
    // 일단 arrangement에 있는 (를 stack에 넣는다
    for(int i = 0; i < arrangement.size(); i++){
        if(arrangement[i]=='(')
            stick.push('(');
        else{
            stick.pop();    // 레이저든 막대기가 끝난거든 ( 하나 빼야 함.
            if(arrangement[i-1]=='(')     // 레이저 등장.
                answer += stick.size();    // 막대기가 레이저에 잘렸음. 스택의 사이즈가 잘린 막대의 갯수.
            else    // 막대기의 끝
                answer++;   // 막대기의 끝 이므로 막대기의 갯수 1개 추가
        }
    }
    return answer;
}
