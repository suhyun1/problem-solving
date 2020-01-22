//10점
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    
    int j=0;
    for(int i=people.size()-1;i>=0;i--){
        //i를 뒤부터 내려오면서 비교하기
        if(i>j && people[i]+people[j] <= limit){
            answer++;
            j++;
        }
        
    }

    
    return people.size()-answer;
}