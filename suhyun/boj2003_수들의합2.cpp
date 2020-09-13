#include <iostream>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int N;
    long long M;
    cin >> N >> M;
    
    int arr[10000];
    for(int i=0; i<N; i++)
        cin >> arr[i];

    int count = 0;
    long long sum = 0;
    int i=0, j=0;
    while(i <= j  && j <= N){
        if(sum == M)    count++;
        
        if(sum < M){
            sum += arr[j];
            j++;
            
        }else if(sum >= M ){
            sum -= arr[i];
            i++;
        }
    }
    
    cout << count << endl;

    return 0;
}
