//6점
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    int size = money.size();
    vector<int> DPfromFirst(size);
    vector<int> DPfromSecond(size);
    DPfromFirst[0] = money[0], DPfromFirst[1] = money[0];
    DPfromSecond[1] = money[1], DPfromSecond[1] = money[1];
    
    //첫번째 집부터 털었을 경우(마지막 집 못 털음)
    for(int i=2; i<size-1;i++){
        DPfromFirst[i] = max(money[i]+DPfromFirst[i-2], DPfromFirst[i-1]);
    }
    //두번째 집부터 털었을 경우(마지막 집 방문)
    for(int i=2; i<size;i++){
        DPfromSecond[i] = max(money[i]+DPfromSecond[i-2], DPfromSecond[i-1]);
    }
    
    answer = max(DPfromFirst[size-2], DPfromSecond[size-1]);
    return answer;
}