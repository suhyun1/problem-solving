#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
	queue<int> q;
	queue<int> t;
	int answer = 0;
	int sum = 0;
	int truckIdx = 0;

	while (1)
	{
		answer++;

		// 현재시간 - 트럭 삽입 시간 = 다리길이  -> 트럭 도착
		if (answer - t.front() == bridge_length)
		{
			sum -= q.front();
			q.pop();
			t.pop();
		}

		// 트럭의 무게가 다리의 무게보다 작으면, 트럭을 삽입
		if (sum + truck_weights[truckIdx] <= weight)
		{
			// 마지막 트럭이 삽입되면 종료
			if (truckIdx == truck_weights.size() - 1)
			{
				// 마지막 트럭 도착시간 추가
				answer += bridge_length;
				break;
			}

			q.push(truck_weights[truckIdx]);
			t.push(answer); // 트럭이 삽입되는 시간 삽입
			sum += truck_weights[truckIdx];
			truckIdx++;
		}
	}

	return answer;
}
