#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    
    int maxValue, K;
    cin >> maxValue >> K;
    
    vector<bool> primes(maxValue+1, true);
    int count = 0;
    for(int i = 2; i <= maxValue; i++){
        if(primes[i]){
            for(int j = i; j <= maxValue; j = j + i){
                if(!primes[j]) continue;
                primes[j] = false;
                count++;
                if(count == K){
                    cout << j <<endl;
                    return 0;
                }
            }
        }
       
    }
    
    return 0;
}
