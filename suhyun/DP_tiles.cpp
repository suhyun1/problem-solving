//2점
#include <string>
#include <vector>

using namespace std;

long long solution(int N) {
    long long answer = 0;
    
    long tiles[81];
    tiles[0] = 1;
    tiles[1] = 1;
    for(int i=2; i<N;i++){
        tiles[i] = tiles[i-2] + tiles[i-1];
    }
    
    
    return 2*tiles[N-2] + 4* tiles[N-1];	// 2*(tiles[N-2] + tiles[N-1]) + 2*tiles[N-1]
}