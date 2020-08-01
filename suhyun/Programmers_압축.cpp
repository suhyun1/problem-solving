#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;


/*
기본적으로 map을 사용하여 색인 저장

현재 위치에서 길이 늘려가며 문자열이 색인에 저장되어있는지 확인
색인에 있는 가장 긴문자열에 대해 색인 번호 출력하고, 그 다음 문자 포함하여 새로 색인에 저장
*/

vector<int> solution(string msg) {
    vector<int> answer;
    
    //A~Z까지 색인저장
    map<string, int> dict;
    for(int i=0; i<='Z'-'A';i++){
        string tmp = "";
        tmp += (char)('A'+i);
        dict[tmp]= i+1;
    }
    
    map<string, int>::iterator it;
    for(int i=0; i<msg.size();){
        string cur = "";
        cur += msg[i];
        string prev = "";
        if(i==msg.size()-1){
            answer.push_back(dict[cur]);
            break;
        }
        for(int j=i+1;j<msg.size();j++){
            prev = cur;
            cur += msg[j];
            it = dict.find(cur);
            if(it != dict.end()){   //사전에 있으면
                if(j==msg.size()-1){
                    answer.push_back(dict[cur]);
                    i=msg.size();
                    break;
                }
                continue;
            }else { //cur이 사전에 없으면 prev가 가장 긴 문자열
                i = j;
                dict[cur] = dict.size()+1;
                answer.push_back(dict[prev]);  
                break;   
            }
        }
        
    }
    
    return answer;
}