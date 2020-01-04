#include <string>
#include <vector>
#include <iostream> 
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int pattern1[] = {1,2,3,4,5};
    int pattern2[] ={2,1,2,3,2,4,2,5};
    int pattern3[] = {3,3,1,1,2,2,4,4,5,5};
  
    int score[3] = {0,0,0};  //각 수포자의 맞힌 개수
    for(int i=0;i<answers.size();i++){
        if(answers[i]==pattern1[i%5]) score[0]++;
        if(answers[i]==pattern2[i%8]) score[1]++;
        if(answers[i]==pattern3[i%10]) score[2]++;    
    }
    
    //최고점수
    int tmp = score[0] > score[1] ? score[0] : score[1];
    int max = tmp > score[2] ? tmp : score[2];

    //최고점수 여러명일 경우 오름차순 정렬
    for(int i=0;i<3;i++)
        if(score[i]==max) answer.push_back(i+1);
    
    return answer;
}