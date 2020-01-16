#include <vector>
#include <string>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds){
    vector<int> answer;
    queue<pair<int, int>> q;

    // 큐에 작업의 갯수와 각각 걸리는 시간 푸시.
    for (int i = 0; i < progresses.size(); i++){
        q.push(make_pair(progresses[i], speeds[i]));
    }

    int day = 0;
    while (q.size() > 0){
        day++;

        int release = 0;    // 릴리즈 될 기능 갯수
        // 작업 진도 + 남은거 * day >= 100 이면 다 한거
        while(q.front().first + q.front().second*day >= 100){
            release++;
            q.pop();
        }if (release != 0 )
            answer.push_back(release);  // 릴리즈 가능한 기능 갯수 answer에 푸시.
    }
    return answer;
}

