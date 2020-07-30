#include <iostream>
using namespace std;

/*
문제해결을 위한 창의적 알고리즘 (중급)

길동이는 n개의 단으로 구성된 계단을 오르려고 한다.
길동이는 계단을 오를 때 기분에 따라서 한 번에 1단 또는 2단을 올라갈 수 있다.
계단의 크기 n이 주어질 때, 길동이가 이 계단을 올라갈 수 있는 모든 경우의 수를 구하는 프로그램을 작성하시오.
*/

int count = 0;

void dfs(int index, int num){
    if(index>num)	//이 경우는 인정안됨
        return;

    if(index==num){
        count++;
        return;
    }
    
    dfs(index+1, num);
    dfs(index+2, num);
    
    
}

int main()
{
    
    int step;
    cin >> step;
    
    dfs(0, step);
    cout << count << endl;

    return 0;
}
