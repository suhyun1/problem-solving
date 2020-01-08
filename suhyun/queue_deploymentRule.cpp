#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    vector<int> releaseDday;
    for(int i=0;i<progresses.size();i++){   //작업 완료 남은 일수
        releaseDday.push_back(ceil((float)(100-progresses[i])/speeds[i]));
    }
    
    for(int i=0;i<releaseDday.size();){  
        
        int j=i+1;
        int cnt = 1;
        while(releaseDday[j] <= releaseDday[i] && j<releaseDday.size()) {  //뒤의 작업이 이미 완료된 경우
            cnt++;
            j++;
        }
        answer.push_back(cnt);
        i = i+cnt;
       
    }
    return answer;
}