#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> PQ;  // 오름차순 우선순위 큐.

    for (int i = 0;i < scoville.size();i++)
        PQ.push(scoville[i]);   // 우선순위 큐에 다 넣자.

    while (PQ.top() < K) {  // scoville 지수가 K 보다 작은 것이 있는 경우.
        if (PQ.size() <= 1) {   // 한개 밖에 없으면 스코빌 지수 K 이상으로 못 만듬.
            answer = -1;
            break;
        }

        int newVal = PQ.top();  // 젤 작은거가 newVal.
        PQ.pop();
        newVal += PQ.top() * 2; // 두 번째 작은거 *2 해서 더한다.
        PQ.pop();
        PQ.push(newVal);    // 믹스 된 스코빌 지수 푸시.
        answer++;
    }
    return answer;
}