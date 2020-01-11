#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//sort함수 사용자 정의
bool compare(string s1, string s2){
    return (s1+s2 > s2+s1)?  true: false;

}

string solution(vector<int> numbers) {
    string answer = "";
    
    //int배열 -> string배열
    vector<string> nums;
    for(int i=0;i<numbers.size();i++)
        nums.push_back(to_string(numbers[i]));
    
    sort(nums.begin(), nums.end(),compare);
         
    for(int i=0;i<nums.size();i++)
        answer += nums[i];
    
     //가장 큰 원소가 0으로 구성된 경우
    if(answer[0] == '0') return "0";
    return answer;
}