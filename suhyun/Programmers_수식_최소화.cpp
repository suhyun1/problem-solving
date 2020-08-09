#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long cal(char priority[3], vector<long long> num, vector<char> op){
    for(int i=0; i<3;i++){
        for(int j=0; j<op.size();j++){
            if(op[j] == priority[i]){
                if(op[j]=='+')
                    num[j] = num[j] + num[j+1];
                else if(op[j]=='-')
                    num[j] = num[j] - num[j+1];
                else if(op[j]=='*')
                    num[j] = num[j] * num[j+1];
                num.erase(num.begin()+j+1);
                op.erase(op.begin()+j);
                j--;
            }
        }
    }
    return abs(num[0]);
}
long long solution(string expression) {
    long long answer = 0;
    
    vector<long long> num;
    vector<char> op;
    int number = 0;
    for(int i=0; i<expression.size();i++){
        if(expression[i]=='*' || expression[i]=='+' ||expression[i]=='-' ){
            op.push_back(expression[i]);
            num.push_back(number);
            number = 0;
        }else{
            number = number *10 + expression[i]-'0';
        }
    }
    num.push_back(number);  //마지막 피연산자도 넣어야 함!
    
    char op_priority[6][3] = {
        {'+', '-', '*'},
        {'+', '*', '-'},
        {'-', '+', '*'},
        {'-', '*', '+'},
        {'*', '+', '-'},
        {'*', '-', '+'},
    };
    
    for(int i=0; i<6;i++){
        answer = max(answer, cal(op_priority[i], num, op));
    }
    return answer;

}