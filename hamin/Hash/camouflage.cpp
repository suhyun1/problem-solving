#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string,int> clothType;  // 의상 종류 : 옷의 갯수 해시 생성.
    
    for (int i = 0; i < clothes.size(); i++){
        auto & c = clothes[i];
        auto & body = c[1];
        if(clothType.find(body) == clothType.end()){
            clothType[body] = 0;
        }
        clothType[body]++;
    }
    
    // 경우의 수 알고리즘 사용.
    for (auto & set : clothType) {
        answer *= (set.second + 1);     // 실제 갯수 보다 + 1 (안 입은 것도 포함)
    }
    
    return answer - 1;
}
