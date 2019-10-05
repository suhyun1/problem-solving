#include <iostream>
#include <queue>
using namespace std;
int T,N,K,cnt;
int arr[100], sol;

int main(){
	cin >> T;	// testcase의 수.
	while (T--){
		sol = -1;
		cin >> N >> K;	// 문서의 수 N, 궁금한 문서 현재 queue의 어떤 위치인지 K.
		priority_queue<int> q;
		for (int i = 0; i < N; i++){
			cin >> arr[i];	// 배열에 중요도 차례로 넣음.
			q.push(arr[i]);	// 큐에도 넣음.
		}
		int cur = 0,cnt=0;
		while (!q.empty() && sol==-1){
			int pos = q.top(); 
			q.pop();
			cnt++;
			for (;;cur=(cur+1)%N){
				if (pos == arr[cur]){
					if (cur == K){
						sol = cnt;
					}
					cur = (cur + 1) % N;
					break;
				}
			}
		}
		cout << sol << endl;
	}
}
