#include <stack>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    stack<int> bucket;
    for(int i=0; i<moves.size();i++){
        int loc = moves[i]-1;   //크레인 위치
        for(int j=0; j<board.size();j++){
            if(board[j][loc]!=0){
                if(!bucket.empty() && bucket.top()==board[j][loc]){	//바구니 맨위 인형과 같은 경우 사라짐
                    bucket.pop();
                    answer += 2;
                }else{
                    bucket.push(board[j][loc]);
		        }
                board[j][loc] = 0;
                break;
            }
        }  
    }
    
    
    return answer;
}