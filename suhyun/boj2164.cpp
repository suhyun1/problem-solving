/*2164 카드2 : 카드 버리고 밑으로 옮기기 반복하기*/
#include <iostream>
#include <queue>

using namespace std;

int main(){
	
	int N;
	queue <int> q;

	cin >> N;
	for(int i=1;i<=N;i++){
		q.push(i);
	}
	
	while(q.size()>1){
		q.pop();	//제일 위의 카드 버리기
		if(q.size()==1) break;
		
		//제일 위의 카드 제일 밑으로 옮기기 
		q.push(q.front()); 	
		q.pop(); 
	}
	
	cout << q.front(); //마지막에 남는 카드 
	
}
