#include <iostream>
#include <cmath>

/*
N-1개 원판을 C를 거쳐 A->B
A의 하나 남은 원판을 A->C
B에 남은 N-1개 원판들 A를 거쳐 B->C
*/


void move(int n, int from, int by, int to){
    if(n==1){   
        printf("%d %d\n", from, to);
    }else{
        move(n-1, from, to, by);
        printf("%d %d\n", from, to);
        move(n-1, by, from, to );
    }
}
int main()
{
    int N;
    scanf("%d",&N);

    printf("%d\n", (1<<N)-1); //가짓수: 2^n-1 
    move(N, 1,2,3);

    return 0;
}
