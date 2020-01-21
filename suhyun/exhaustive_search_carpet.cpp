//5점
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {  
    vector<int> answer;
    
    int total_size = brown + red;
    //i:전체의 가로길이
    for(int i=3; i<=total_size;i++){
        int temp = total_size /i;
        
        if(total_size %i ==0 && (i-2)*(temp-2)==red && temp <= i){  //(i-2)*(temp-2)==red 이 조건이 중요!
            answer.push_back(i);
            answer.push_back(temp);
            break;
        }
    }
    
    return answer;
}