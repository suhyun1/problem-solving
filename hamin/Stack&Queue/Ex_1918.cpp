#include <stdio.h>
#include <string.h>
#include <stack>

using namespace std;

char s[100];

int main() {
    int i;
    scanf("%s",s);
	
	stack <char> op;
	
    for(i = 0; i < strlen(s); ++i) {
        switch(s[i]) {
        case '(':
            op.push('('); 
            break;
        case ')':
            while(!op.empty() && op.top()!='(') { 
				printf("%c",op.top()); 
				op.pop();  
			}
            if(op.top() == '(') 
				op.pop();
			break;
         case '*': case '/':
            while(!op.empty() && op.top() != '+' && op.top() != '-' && op.top() != '(' ) { 
				printf("%c", op.top()); 
				op.pop(); 
			}
            op.push(s[i]);
            break;
         case '+': case '-':
             while(!op.empty() && op.top() != '(' ) { 
				 printf("%c", op.top()); 
				 op.pop(); 
			 }
             op.push(s[i]);;
             break;
         default:
             printf("%c",s[i]);
             break;
        }
    }
    while(!op.empty()) { 
		printf("%c", op.top()); 
		op.pop(); 
	}
    printf("\n");
 
    return 0;
}
