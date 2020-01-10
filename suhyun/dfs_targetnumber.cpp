#include <string>
#include <vector>
#include <stack>

using namespace std;
int answer;

void dfs(vector<int> numbers, int target, int index, int sum){
    if(numbers.size()==index){
        if(sum == target)  {
            answer++;
            return;
        } 
    }
    else{
        dfs(numbers, target,index+1, sum+numbers[index]);
        dfs(numbers, target,index+1, sum-numbers[index]);
    } 
    
}

int solution(vector<int> numbers, int target) {
    answer = 0;

    dfs(numbers, target, 0, 0);
  
    return answer;
}

