//O(n)가능

#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    unordered_map<string,int> participant_score;
    
    for(auto p : participant){
        participant_score[p] ++;
    }
    
    for(auto c : completion){
        participant_score[c] --;
    }

    for(auto name : participant_score){
        if(name.second != 0)
            return name.first;
    }
    

}