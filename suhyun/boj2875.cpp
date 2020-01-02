/*2875 인턴or대회: 제외해야하는 인원 주어질때 최대 팀 개수 */
#include<iostream>

using namespace std;

int main(){
	int n, m, k;
	
	cin >> n >> m >>k;
	
	while(k!=0){
		
		if(n>=m*2){	//여학생 인턴십으로 빼기
			k--;
			n--;
		}
		else{ 		//남학생 빼기 
			k--;
			m--;
		}
	}
	cout << (n>=m*2? m: n/2); 	//최대 팀 개수 구하기 
}
