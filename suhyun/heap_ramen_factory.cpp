//11점
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    
    priority_queue<int> big_order;
    
    int index = 0;
    for(int day=0 ;day<k ;day++){
        if(day == dates[index]){
            big_order.push(supplies[index]);
            index++;
        }
        if(stock == 0) {
            stock = big_order.top();
            big_order.pop();
            answer ++;
        }
        
        stock--;
    }
        
    return answer;
}