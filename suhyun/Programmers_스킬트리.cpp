#include <vector>
#include <string>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(int i = 0; i < skill_trees.size(); i++){
        int skill_level = 0;
        bool flag = true;
        for(int j = 0; j < skill_trees[i].length(); j++){
            if(skill_trees[i][j] == skill[skill_level]){
                skill_level++;
                continue;
            }
            for(int k = skill_level + 1; k < skill.length(); k++){
                if(skill_trees[i][j] == skill[k]){
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
        }
        if(flag) answer++;
    }
    
    return answer;
}