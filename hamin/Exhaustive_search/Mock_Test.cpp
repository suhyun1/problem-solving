#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> one = {1,2,3,4,5};
vector<int> two = {2,1,2,3,2,4,2,5};
vector<int> thr = {3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {

    vector<int> answer;
    vector<int> score(3);    // 기본값(0)으로 초기화 된 3개의 원소를 가지는 vector score 생성.

    // 각각 몇개씩 맞췄는지 비교.
    for(int i=0; i<answers.size(); i++){
        if(answers[i] == one[i%one.size()])
            score[0]++;
        if(answers[i] == two[i%two.size()])
            score[1]++;
        if(answers[i] == thr[i%thr.size()])
            score[2]++;
    }

    // max_score에 score 벡터 안에 있는 최댓값 삽입.
    int max_score = *max_element(score.begin(), score.end());

    //
    for(int i=0; i<3; i++){
        if(score[i] == max_score)
            answer.push_back(i+1);
    }

    return answer;
}