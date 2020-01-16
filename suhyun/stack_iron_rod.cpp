#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int solution(string arrangement) {
    int answer = 0;
    
    stack<char> s;

    for(int i=0;i<arrangement.size();i++){
        //여는 괄호: stack에 push
        if(arrangement[i]=='(')
           s.push('(');
        
        //닫는 괄호: stack에서 pop
        else if(arrangement[i]==')'){
            s.pop();
            if(arrangement[i-1]=='(')   //레이저
                answer += s.size();
            else    //쇠막대기 끝
                answer += 1;                   
        }         
            
    }
     
    return answer;
}