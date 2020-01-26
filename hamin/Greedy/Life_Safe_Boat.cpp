#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    // 우선 내림차순 정렬하기.
    sort(people.begin(), people.end(), greater<int>());
    
    for(int i = people.size()-1; i >= 0; i--){
        if(people[i] + people[i-1] <= limit){
            answer++;
            people.pop_back();
            people.pop_back();
        }
    }
    
    for(int i = people.size()-1; i>= 0; i--){
        cout << people[i] << ' ';
    }
    return answer;
}
