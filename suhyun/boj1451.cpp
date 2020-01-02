/*잃어버린 괄호: 괄호쳐서 식의 값 최소로 만들기*/
#include <iostream>
using namespace std;


int main(){
	string s;
	cin >> s;
	
	int flag = 0, res=0, num=0;
	int i=0;
	while(i!=s.length()){
		
		//숫자 저장 
		if('0' <= s[i] && '9'>= s[i]) {
			int tmp = s[i]-'0';
			num = num*10 +tmp;
		}
		else{ //연산자 
			
			if(flag == 0 ) res += num;	//마이너스 안만남 
			else res -=num; //마이너스 만난 이후 
			
			if (s[i]=='-' && flag ==0) {	//마이너스 처음 만남 
				flag = 1;
			}
			
			num = 0; //임시 숫자 초기화 
		}
		i++;
	}
	
	//마지막 수 연산
	if(flag==0) res+=num;
	else res -=num;
	
	cout<<res;
}
