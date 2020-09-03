#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool isCorrectBracket(string s){
    int cnt = 0;
    for(int i=0; i<s.length();i++){
        if(s[i] =='(') cnt++;
        else{
            if(cnt == 0) 
                return false;
            cnt--;
        }
    }
    return true;   
}

string recursion(string s){
    if(s=="")    return s;
    int cnt = 0;
    string u = "", v = "";
    for(int i=0; i<s.length();i++){
        if(s[i] == '(') cnt++;
        else if(s[i] ==')') cnt--;
        if(cnt == 0){
            u = s.substr(0,i+1);
            v = s.substr(i+1);
            break;
        } 
    }

    string tmp ="";
    if(isCorrectBracket(u))
        return u+recursion(v);
    else{
        tmp += "("+recursion(v)+")";
        u = u.substr(1,u.length()-2);
        for(int i=0; i<u.length();i++){
            if(u[i]=='(') u[i] = ')';
            else u[i] = '(';
        }
        tmp += u;
        return tmp;
    }
    
 
}
string solution(string p) {

    if(isCorrectBracket(p))
        return p;
    
    string answer = recursion(p);
    return answer;
}