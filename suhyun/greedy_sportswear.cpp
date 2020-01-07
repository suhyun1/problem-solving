#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    int student[31];     
    for(int i=0; i<n;i++)   
        student[i] =1; //1개씩 가지고 있는 것으로 초기화
    
    //여벌있는 학생
    for(int i=0; i<reserve.size();i++)
        student[reserve[i]-1]++;
    
    //도난당한 학생
    for(int i=0; i<lost.size();i++)
        student[lost[i]-1]--;
    

    //앞뒤로 여벌있는지 체크
    for(int i=0;i<n;i++){
        if(student[i]==0){

            if(student[i+1] ==2){
                student[i+1]--;
                student[i]++;
            }
            else if(student[i-1] ==2 ){
                student[i-1]--;
                student[i]++;   
            }
        }
    }
    
    for(int i=0;i<n;i++){
        if(student[i]>0)    
            answer++;
    }
        
    return answer;
}