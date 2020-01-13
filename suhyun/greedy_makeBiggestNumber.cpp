#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {

    while(k>0){       
        for(int i=0; i<number.size();i++ ){
            //다음 원소와 비교해 작으면 삭제  
            if(number[i]<number[i+1] || i==number.size()-1){  //뒤의 조건은 연달아 중복되는 숫자에 대비한 것
                number.erase(number.begin()+i);
                k--;
                break;
            }   
        }
    }
    
    return number;
}