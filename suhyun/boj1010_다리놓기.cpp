#include <iostream>
using namespace std;
 //다리를 지을 수 있는 경우의 수(다리는 겹쳐질수 없다!)
int main()
{
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    
    long long DP[30][30];

    for(int j=0; j<30;j++){
        for(int k=j; k<30;k++){
            if(k==j || j==0)    DP[j][k] = 1;
            else DP[j][k] = DP[j-1][k-1] + DP[j][k-1];
        }
    }
        
    for(int i=0;i<T;i++){
        int N, M, ans;
        cin >> N >> M;
        cout << DP[N][M] << endl;
 
    }
    

    return 0;
}
