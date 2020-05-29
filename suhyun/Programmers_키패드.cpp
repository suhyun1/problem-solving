#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    int left_x =0, left_y=3;
    int right_x=2, right_y=3;
    for(int i=0; i<numbers.size();i++){
        if(numbers[i]==1 ||  numbers[i]==4 ||numbers[i]==7 ){
            answer += "L";
            left_x = 0;
            left_y = numbers[i]/3;
        }else if(numbers[i]==3 ||  numbers[i]==6 ||numbers[i]==9 ){
            answer += "R";
            right_x = 0;
            right_y = (numbers[i]/3)-1;
        }else{
            int dest_x = 1;
            int dest_y = (numbers[i]==0 ? 3 : numbers[i]/3);
            int l_dist = (abs(dest_x - left_x)+abs(dest_y - left_y));
            int r_dist = (abs(dest_x - right_x)+abs(dest_y - right_y));

            if(l_dist < r_dist ){
                answer += "L";
                left_x = dest_x;
                left_y = dest_y;
            }else if(l_dist > r_dist ){
                answer += "R";
                right_x = dest_x;
                right_y = dest_y;
            }else{
                if(hand=="left"){
                    answer += "L";
                    left_x = dest_x;
                    left_y = dest_y;
                }else{
                    answer += "R";
                    right_x = dest_x;
                    right_y = dest_y;
                }
           
            }
        }
            
        
    }
    return answer;
}