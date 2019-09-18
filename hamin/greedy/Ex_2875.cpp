#include <iostream>
#include<algorithm>
using namespace std;

int main() {

	int N, M, K;
	cin >> N >> M >> K;

	int team = min(N / 2, M);	// 최대 팀 갯수.
	for (int i = team; i >= 0; i--) {
		if (M + N - 3 * i >= K)		// 전체 인원 - (팀 갯수*3) 값이 k보다 크거나 같다면.
		{
			cout << i << "\n";
			break;
		}
	}
	return 0;
}
