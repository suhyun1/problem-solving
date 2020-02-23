//4점
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    
    sort(routes.begin(), routes.end());
    
    vector<int> overlap{routes[0][0], routes[0][1]}; //겹치는 구간 {처음, 끝}

    for(int i=1; i<routes.size();i++){
        if(routes[i][0] < overlap[1] && overlap[1] < routes[i][1]){
            overlap[0] = routes[i][0];
            //overlap[1]은 그대로
        }else if(routes[i][1] < overlap[1]){
            overlap[0] = routes[i][0];
            overlap[1] = routes[i][1];
        }else if(routes[i][0] > overlap[1]){
            overlap[0] = routes[i][0];
            overlap[1] = routes[i][1];
            answer++;
        }  
    }
    
    return answer;
}