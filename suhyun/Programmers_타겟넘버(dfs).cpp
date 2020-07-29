#include <string>
#include <vector>
using namespace std;

vector<int> nums;
int size, target_num;
int answer = 0;

void dfs(int index, int output){
    if(index == size){
        if(output == target_num){
            answer ++;
        }
        return;
    }
    
    dfs(index+1, output+nums[index]);
    dfs(index+1, output-nums[index]);
    
}
int solution(vector<int> numbers, int target) {
    
    size = numbers.size();
    target_num = target;
    nums = numbers;
    
    dfs(0, 0);
    
    return answer;
}