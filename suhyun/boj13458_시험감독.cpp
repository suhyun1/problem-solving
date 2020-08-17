#include <iostream>
#include <vector>
using namespace std;

//필요한 감독관의 최소 수를 출력

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
	
    int N;
    cin >> N;
    vector<int> A(N);   //각 시험장의 응시자 수
    int B, C;           //총감독, 부감독의 감시 응시자 수
    for(int i=0; i<N;i++)
        cin >> A[i];
    cin >> B >> C;
    
    long long cnt = 0;
    for(int i=0; i<N;i++){
        A[i] = A[i] - B;
        cnt++;
        if(A[i]<=0) continue;
        
        if(A[i] % C == 0)
            cnt += A[i]/C;
        else
            cnt += A[i]/C+1;
 
        
    }
    cout << cnt ;
    return 0;
}
