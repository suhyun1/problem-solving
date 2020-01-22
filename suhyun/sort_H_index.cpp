//9점
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end(), greater<int>()); //내림차순
    
    int size = citations.size();
    for(int i=0; i<size ;i++){
        if(citations[i] <= answer){
            break;
        }
        answer++;
        
    }
   
    
    return answer;
}