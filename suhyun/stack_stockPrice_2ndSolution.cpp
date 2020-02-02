#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {

    vector<int> answer;
    int size = prices.size();
    
    for(int i=0; i<size;i++){
        int time=0;
        
        for(int j=i+1; j<size;j++){
            time++;
            if(prices[i] > prices[j] || j == size-1){
                answer.push_back(time);
                break;
            }
        }
    }
    answer.push_back(0);
    return answer;
}