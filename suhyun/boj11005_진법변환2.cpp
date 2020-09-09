#include <iostream>
#include <stack>

using namespace std;


void convert(int N, int B){
    
    stack<char> result;
    while(1){
        if(N == 0)    break;
        int mod = N % B;
        N /= B;
        
        if(mod>=10)
            result.push('A'+mod-10);
        else
            result.push(mod+'0');
        
    }
    
    while(!result.empty()){
        cout << result.top();
        result.pop();
    }
}

int main()
{
    int N, B;
    cin >> N >> B;
    
    convert(N, B);

    return 0;
}
