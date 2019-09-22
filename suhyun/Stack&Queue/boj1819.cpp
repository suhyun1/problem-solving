#include <iostream>
#include <stack>
using namespace std;

int getPriority(char op){	
	if(op=='(' ) return 0;
	else if(op=='+' || op=='-') return 1;
	else return 2;
}

int main(){
	
	string s;
	cin >> s;
	
	stack <char> op;
	
	for(int i=0 ; i<s.length(); i++){
		
		if(s[i] =='('){ 	//왼쪽괄호면 push 
			op.push(s.at(i));
		}
		else if(s[i] ==')'){	 //왼쪽 괄호 나올때까지 pop 
			while(op.top()!='('){	
				cout << op.top();
				op.pop();
			}
			if(op.top()=='(') op.pop(); 	
		}
		else if(s[i]=='*'||s[i]=='/'||s[i]=='+'||s[i]=='-'){	//연산자일경우 push 
			
			while(!op.empty() && (getPriority(s.at(i))<=getPriority(op.top())) ){	//기존의 것이 우선순위 높거나 같으면 기존연산자 pop
				cout << op.top();
				op.pop();
			}
			op.push(s.at(i));
		}
		else // 피연산자(A~Z)는 바로 출력 
			cout << s[i] ;
	}
	
	while(!op.empty()){ 	//스택 나머지 연산자 출력 
		cout << op.top();
		op.pop();
	}
	return 0;
}

