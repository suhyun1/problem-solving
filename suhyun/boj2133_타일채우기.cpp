#include <iostream>
using namespace std;

//3×N 크기의 벽을 2×1, 1×2 크기의 타일로 채우는 경우의 수를 구해보자.


int main()
{
    int N;
    cin >> N;
    
    int tile[31] = {0};
    tile[0] = 1;
    tile[2] = 3;
    
    if(N%2 ==0){
        for(int i=4 ;i<=N;i=i+2){
        
            tile[i] = tile[i-2]*3;
            for(int j=4; i-j>=0; j=j+2)
                tile[i] += tile[i-j]*2;
        }
    }
    
    cout <<tile[N] <<endl;
    
    return 0;
}
