#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 사용자 정의 함수 -> 붙였을 때 더 큰 것으로 정렬
bool compare(string s1, string s2){
    return (s1+s2 > s2+s1)? true : false;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    // int 배열 -> string 배열
    vector<string> nums;
    for(int i = 0; i < numbers.size(); i++)
        nums.push_back(to_string(numbers[i]));
    
    // compare 함수를 이용하여 정렬.
    sort(nums.begin(), nums.end(), compare);
    
    for(int i = 0; i < nums.size(); i++)
        answer += nums[i];
    
    // 0이 가장 큰 수로 판명 되면 0을 리턴
    if(answer[0] == '0')
        return "0";
    
    return answer;
}