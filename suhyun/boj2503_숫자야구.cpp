#include <iostream>
#include <string>
#include <vector>

using namespace std;

//완전탐색. 가능한 수를 모두 수행해보자
//입력: 123 1 1 (123: 1S 1B)
//출력: 가능한 수
int main()
{
    int N;
    cin >> N;
    vector<vector<int> > question(N, vector<int>(3)); 

    for(int i=0; i<N;i++){
        cin >> question[i][0] >> question[i][1] >> question[i][2]; 
    }
   
    vector <string> answer;
    for(int i=123; i<=987;i++){
        string tmp = to_string(i);
        if(tmp[0] == '0' || tmp[1]== '0' || tmp[2]== '0')   //0은 없음
            continue;
        if(tmp[0] == tmp[1] || tmp[2] == tmp[0] ||tmp[2] == tmp[1] )    //세자리 중에 같은수 있는 경우 
            continue;
            
        bool flag = true;
        for(int j=0; j<N;j++){
            string num = to_string(question[j][0]);
            int s_cnt = 0;
            if(tmp[0] == num[0])
                s_cnt ++;
            if(tmp[1] == num[1])
                s_cnt ++;
            if(tmp[2] == num[2])
                s_cnt ++;
            
            if(s_cnt != question[j][1])  { //strike 개수 맞지 않으면 탙락
                flag = false;
                break;
            }
            
            int b_cnt = 0;
            if(tmp[0] == num[1] || tmp[0] == num[2])
                b_cnt ++;
            if(tmp[1] == num[0] || tmp[1] == num[2])
                b_cnt ++;
            if(tmp[2] == num[0] || tmp[2] == num[1])
                b_cnt ++;
            
            if(b_cnt != question[j][2])  { //ball 개수 맞지 않으면 탙락
                flag = false;
                break;
            }
            
        }
        if(flag)
            answer.push_back(tmp);

    }
    
    cout << answer.size() <<endl;
   
    return 0;
}
