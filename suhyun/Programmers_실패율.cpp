//5점
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<double, int> &a, const pair<double, int> &b)
{
    if(a.first == b.first)
        return a.second < b.second;
    else
        return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> stageCount(N+2,0);
    for(int i=0; i<stages.size();i++){
        stageCount[stages[i]]++;      
    }
    
    int sum = 0;
    for(int i=0; i<stageCount.size();i++){
        sum += stageCount[i];
    }
    //실패율계산
    int cumsum = 0;
    vector <pair<double, int>> failRatio;
    for(int i=1;i<stageCount.size()-1; i++){  //stage 1부터 존재
        int userCount = stageCount[i];
        
        if(userCount == 0){
            failRatio.push_back(pair<double,int>(0, i));
        }else{
            failRatio.push_back(pair<double,int>((double)userCount/(sum-cumsum), i));
        }
        cumsum += userCount;
    }
    sort(failRatio.begin(), failRatio.end(), cmp);
    for(int i=0; i<failRatio.size();i++){
        answer.push_back(failRatio[i].second);
    }
   
    return answer;
}