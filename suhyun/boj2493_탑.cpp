#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*
기본적으로 스택에 (높이, 인덱스) 쌍으로 삽입!
1. 스택의 top < 입력값이면 top 꺼내는 것 empty일때까지 반복
2. 스택 비어있으면 => 0 출력
비어있지 않으면 => top의 인덱스 값 출력
3. 입력값 stack에 push
*/

int main()
{
    
    int N;
    cin >> N;
    vector<int> tower(N);
    stack<pair<int,int> > s;
    
    int tmp = 0;
    for(int i=0; i< N;i++){
        cin >> tmp;
        tower[i] = tmp;
    }
    
    for(int i=0; i< N;i++){
        tmp = tower[i];
        
        while(!s.empty()){
            if(s.top().first < tmp){
                s.pop();
            }else{
                break;
            }
        }
        if(s.empty())
            cout << "0 ";
        else
            cout << s.top().second<< " ";
        
        s.push(pair<int,int>(tmp, i+1));
    }


    return 0;
}
