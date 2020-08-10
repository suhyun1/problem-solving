#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
bool checked[8];
set<string> s;

void dfs(vector<string>& user_id, vector<string>& banned_id, int idx, string comb){
    if(idx == banned_id.size()){
        sort(comb.begin(), comb.end());
        s.insert(comb);
        return;
    }
    for(int i=0; i<user_id.size();i++){
        if(checked[i])
            continue;
        if(user_id[i].size() != banned_id[idx].size()) 
            continue;
        
        bool flag = true;
        for(int j=0; j<user_id[i].size();j++){
            if(banned_id[idx][j] == '*')
                continue;
            if(user_id[i][j] != banned_id[idx][j]){
                flag = false;
                break;
            }
        }
        if(flag){
            checked[i] = true;
            dfs(user_id, banned_id, idx+1, comb+to_string(i) );
            checked[i] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    
    dfs(user_id, banned_id, 0,"");

    return s.size();
}