#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    
    unordered_map<string,int> item_type;
    
    for(int i=0;i<clothes.size();i++){
        item_type[clothes[i][1]]++;
    }
    
    answer = 1;
    for(auto type: item_type){
        answer *= (type.second+1);  //실제 개수보다 +1 (안입는 것도 포함)
    }
    answer--;   //모두 안 입은 경우 -1
    
    
    return answer;
}