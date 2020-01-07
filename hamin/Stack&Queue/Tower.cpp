#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    stack<int> s;

    // 벡터를 뒤(i) 부터 비교
    for(int i=heights.size()-1; i>=0; i--){
        bool flag = true;
        // 바로 앞(j)의 것과 비교
        for(int j=i-1; j>=0; j--){
            // 앞(j)의 것이 큰 경우
            if(heights[i] < heights[j]){
                // 스택에 몇 번째 타워인지 넣기
                s.push(j+1);
                // 이제 그만 비교해도 됨.
                flag = false;
                break;
            }
        }
        // 앞에 더 큰 것이 없다면 스택에 0을 넣기.
        if(flag)
            s.push(0);
    }
    // 스택에 있는것을 모두 answer에 넣기.
    while(!s.empty()){
        answer.push_back(s.top());
        s.pop();
    }
    return answer;
}