/*1966 프린터큐: queue에서 문서의 중요도 고려하여 인쇄 순서 정하기 */
#include <iostream>
#include <queue>

using namespace std;

int main(){
	
	int testCase;
	cin >> testCase;
	
	for(int i=0;i<testCase;i++){
		
		int N, M;	//N개의 문서 중 M번째 문서 
		cin >> N >> M;	
		
		priority_queue <int> imp;	
		queue <pair<int, int> > q;	//(인덱스, 중요도)의 쌍  
		
		int val;
		for(int j=0;j<N;j++){
			cin >> val;	
			imp.push(val);
			q.push(pair<int,int>(j, val));
		}
		
		int index=0;	//알고싶은 문서의 출력순서 
		while(!q.empty()){
			if(imp.top()== q.front().second){	//현재 문서가 중요도 가장 큰값인 경우 
				index++;
				if(q.front().first == M)	break; 	//M번째 문서면 while 종료 
				imp.pop();
				q.pop();
			}
			else{	//나머지 문서의 중요도 더 큰 경우: 맨앞 꺼내서 뒤에 push 
				int tmp_idx, tmp_val;
				tmp_idx=q.front().first;
				tmp_val=q.front().second;
				q.pop();
				q.push(pair<int,int>(tmp_idx, tmp_val));
			}
			
		}
		cout << index<<endl;	
	}
}
