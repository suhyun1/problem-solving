#include <string>
#include <vector>

using namespace std;

vector<string> strtok(string line, char d){
    vector<string> result; 
    string prev = "";
    for(int i = 0; i < line.length(); i++){
        if(line[i] == d){
            result.push_back(prev);
            prev = "";
        }
        else 
            prev += line[i];
    }
    result.push_back(prev);
    return result;
}

int solution(vector<string> lines) {
    int answer = 0;
    vector<pair<int,int>> check_time;   //(시작시간, 끝 시간)
    for(int i = 0; i < lines.size(); i++){
        vector<string> token = strtok(lines[i], ' ');
        vector<string> time = strtok(token[1], ':');
        int complete_time = (stod(time[0]) * 3600 + stod(time[1]) * 60 + stod(time[2])) * 1000;
        int start_time = complete_time - stod(token[2]) * 1000 + 1;
        check_time.push_back({start_time, complete_time});
    }
    
    for(int i = 0; i < check_time.size(); i++){
        int cnt = 1;
        int complete = check_time[i].second;
        int limit = complete + 999;
        for(int j = i+1; j < check_time.size(); j++){
            if(complete <= check_time[j].second && limit >= check_time[j].first ){
                cnt++;
            }
        }
        if(answer < cnt) answer = cnt;
    }
    
    
    return answer;
}