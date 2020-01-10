#include <vector>
#include <iostream>

using namespace std;

int answer = 0;     // target 넘버에 맞게 더해진 경우의 수.

void DFS(vector<int> numbers, int target, int sum, int index){
    if(index == numbers.size()){        // numbers에 들어있는 숫자 갯수 만큼만 더해야.
        if(sum == target){      // 더한 것이 타겟과 같다면
            answer++;           // 만족하는거 하나 찾은거임
            return;
        }
        return;
    }
    DFS(numbers, target, sum + numbers.at(index), index + 1);       // 트리에서 깊이(index) +1 후 다음 노드(배열의 요소) +하기
    DFS(numbers, target, sum - numbers.at(index), index + 1);       // 트리에서 깊이(index) +1 후 다음 노드(배열의 요소) -하기
}

int solution(vector<int> numbers, int target){

    DFS(numbers, target, 0,  0);    // numbers는 사용할 수들, target은 합쳐서 나올 수, sum은 현재 더해진 수, index는 현재 더한 갯수.

    return answer;
}

int main() {
    vector<int> numbers = {1,1,1,1,1};
    int target = 3;
    int answer = solution(numbers, target);
    cout << "The answer is : "<< answer << endl;
    return 0;
}

