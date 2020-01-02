/*2841 외계인의 기타연주: 음 연주시 손가락 가장 적게 움직이는 횟수*/
#include <iostream> 
#include <stack>
using namespace std;

int main(){
	
	int N, P; //N: (연주할)음의 수, P: 프렛의 수
	int cnt=0; //움직임 count 
	stack <int> s[7]; //줄 6개  (인덱스 1~6 사용)
	
	cin >> N >> P;
	for(int i=0;i<N;i++) {
		int line, pret;	//줄의 번호, 프렛의 번호 
		cin >> line >> pret;
			
		//누르려는 프렛이 이전에 누른 것보다 더 작은 case
		while (!s[line].empty()&& s[line].top() > pret) {	
			 s[line].pop();
			 cnt++;	//떼는 횟수 count 
		}
		if(!s[line].empty()&& s[line].top() == pret) continue; //누르지 않는 유일한 case 
		
		//누르는 모든 case 
		cnt++;	
		s[line].push(pret);
	}
	
	cout << cnt;
}
