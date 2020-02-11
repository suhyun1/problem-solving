#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    
    priority_queue<int, vector<int>> storage;
    
    int index = 0;
    for(int day=0; day<k; day++){
        if(day == dates[index]){    // 공급되는 날이라면.
            storage.push(supplies[index]);    // 공급량을 storage에 추가.
            index++;    // index는 무슨 역할?
        }
        if(stock == 0){
            stock = storage.top();    // top에 있는 원소 반환.
            storage.pop();  // 공급받은 것 storage에 넣어 두었던 것이 필요했던것이니 pop 해서 사용.
            answer++;   // 공급 받은것 필요 했다는 것이다.
        }
        stock--;    // 하루에 1톤씩 사용.
    }
    return answer;
}
