/*14717 앉았다: 앉았다 게임 규칙에 따라 해당  이길 확률 구하기*/
#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
	int n1, n2;
	int total = 153; //전체 경우의수 
	int numOfCase=0, digit; //경우의 수, 합의 일의자리 
	
	cin >> n1 >> n2;
	
	if(n1==n2){	//땡의 경우 
		numOfCase = 143+n1;
	}
	else{
		digit = (n1+n2)%10; //합의 일의자리 
		
		for(int i=1;i<=10;i++){
			for(int j=1;j<=10;j++){
				if( (i<j) && ((i+j)%10 < digit)){	
					
					if(i==n1 || i==n2 || j==n1 || j==n2) //이미 뽑은 것과 중복되는 경우 
						numOfCase+=2;
						
					else
						numOfCase+=4;
				}
			}
		}
	}
	printf("%.3f", (float)numOfCase/total);
	
}
