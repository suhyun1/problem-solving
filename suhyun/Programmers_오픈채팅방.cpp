#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> nickname; //id,닉네임 쌍
    vector <pair<string, bool> > in_out; //id,in(true) or out(false) 쌍
    
    for(int i=0; i<record.size();i++){
        vector<string> msg;
        string tmp = "";
        for(int j=0; j<record[i].length();j++){
            if(record[i][j] == ' '){
                msg.push_back(tmp);
                tmp ="";
            }else{
                tmp += record[i][j];
            }
        }
        msg.push_back(tmp);
        
        if(msg[0] == "Enter"){
            nickname[msg[1]] = msg[2];
            in_out.push_back(make_pair(msg[1],true ));
        }else if(msg[0] == "Leave"){
            in_out.push_back(make_pair(msg[1],false));
        }else if(msg[0] == "Change"){
            nickname[msg[1]] = msg[2];
        }
    }
    
    for(int i=0; i<in_out.size();i++){
        if(in_out[i].second){
            answer.push_back(nickname[in_out[i].first]+"님이 들어왔습니다.");
        }else{
            answer.push_back(nickname[in_out[i].first]+"님이 나갔습니다.");
        }
    }
    
    return answer;
}

