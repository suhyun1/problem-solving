//5점
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> weight) {
    int answer = 0;
    
    sort(weight.begin(), weight.end());
    int maxMeasure = weight[0];
    
    for(int i=1; i<weight.size();i++){
        if(weight[i] > maxMeasure+1 ){
            break;
        }else {
            maxMeasure += weight[i];
        }
    }
    answer = maxMeasure +1;
    return answer;
}