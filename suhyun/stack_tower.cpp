#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    
    bool flag;
    int j, size = heights.size();
    for(int i=size-1;i>=0;i--){
        for(j=i-1; j>=0;j--){
            if(heights[i]<heights[j]){
                flag = true;    
                break;
            }
        }
        answer.push_back(flag ? j+1: 0);  //신호 수신한 탑 있으면 탑 순서, 아니면 0 
    }
    
    reverse(answer.begin(), answer.end());
        
    return answer;
}