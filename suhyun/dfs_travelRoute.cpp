//9점
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer;

bool dfs(string start, vector<vector<string>> tickets, vector<bool> visit, int cnt){
    answer.push_back(start);

    for(int i=0; i< tickets.size();i++){
        if(tickets[i][0]==start && !visit[i]){
            visit[i] = true;
            bool finished = dfs(tickets[i][1] , tickets, visit, cnt+1);
            if(finished)    
                return true;
            else 
                visit[i] = false;
        }
    }
    if(cnt == tickets.size())
        return true;

    answer.pop_back();
    return false;

}
vector<string> solution(vector<vector<string>> tickets) {
    
    vector<bool> visit(tickets.size(), false);
    sort(tickets.begin(), tickets.end());
    dfs("ICN", tickets, visit,0);
    
    return answer;
}