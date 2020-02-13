//10점
#include <string>
#include <vector>
using namespace std;

int solution(string name) {
    int answer = 0;
    int size = name.size();

    string compare ="";
    for(int i=0; i<size;i++){
        compare += 'A';
    }
    
    int index = 0;
    while(compare != name){
        
        int right_index = 0;
        int left_index = 0;
        for(int i=0; i<size; i++){
            //오른쪽으로 이동시 
            if(index + i < size)
                right_index = index+i;
            else
                right_index = index+i-size;      
            
            //왼쪽으로 이동
            if( index - i >= 0)
                left_index = index- i;
            else
                left_index = index-i+size;
                      
            if(compare[right_index] != name[right_index]){
                index = right_index;        
            }else if(compare[left_index] != name[left_index]){
                index = left_index;
            }else{
                continue;
            }
            
            int up_count = name[index] - 'A';
            int down_count = 'Z' - name[index] + 1;
            answer += (up_count > down_count ? down_count : up_count);
            
            compare[index] = name[index];
            answer += i;
            break;
        }

    }

    return answer;
}