#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    // 우선 오름차순 정렬하기.
    sort(people.begin(), people.end(), greater<int>());
    
    for(int i = 0; i < people.size(); i++){
        if(people[i] + people[people.size()-1] <= limit){
            people.erase(people.begin() + people.size() - 1);
        }
        answer++;
    }
    return answer;
}
