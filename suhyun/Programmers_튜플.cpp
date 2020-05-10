#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool visited[100001];
bool cmp(const vector<int> &a,const vector<int> &b){
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    
    vector<vector<int>> sets;
    vector<int> temp;
    string num = "";
    for(int i=1;i<s.size()-1;i++){
        if(s[i]>='0' && s[i]<='9'){
            num += s[i];
        }else if( s[i]==','){
            temp.push_back(stoi(num));
            num = "";
        }else if(s[i]=='{' ){
            continue;
        }else if(s[i]=='}'){
            if(num!= ""){   //집합에 원소 하나인 경우
                temp.push_back(stoi(num)); 
                num = "";
            }
            sets.push_back(temp);
            temp.clear();
            i++;
        }
    }
    
    //원소 개수 순 나열
    sort(sets.begin(), sets.end(), cmp);
    
    for(int i=0; i<sets.size();i++){
        for(int j=0; j<sets[i].size();j++){
            if(!visited[sets[i][j]]){
                visited[sets[i][j]] = true;
                answer.push_back(sets[i][j]);
                break;
            }
        }
    }
    
    return answer;
}