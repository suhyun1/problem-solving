#include <iostream>

using namespace std;

int map[128][128];
int cnt = 1;

void putTile(int a, int b, int k, int y, int x){ //a,b는 시작 위치 x,y는 빈곳 위치

    if(k==1){
        map[a][b] = map[a+1][b] = map[a][b+1]  = map[a+1][b+1] = cnt++;
        return;
    }
        
    int len = 1 << k-1;
    //각 사분면에 빈곳 있는지 확인
    if(y<len+a && x<len+b)   //1사분면에 존재
        putTile(a, b, k-1, y, x);
    else                    //1사분면에 존재x
        putTile(a, b, k-1, a+len-1, b+len-1);
        
    if(y<len+a && x>=len+b) //2사분면
        putTile(a, b+len, k-1, y, x);
    else 
        putTile(a, b+len, k-1, a+len-1, b+len);

    if(y>=len+a && x<len+b){ //3사분면
        putTile(a+len, b, k-1, y, x);
    }
    else
        putTile(a+len, b, k-1, a+len, b+len-1);
        
    if(y>=len+a && x>=len+b)  //4분면
        putTile(a+len, b+len, k-1, y, x);
    else
        putTile(a+len, b+len, k-1, a+len, b+len);
        
    if(y<len+a && x<len+b){     //1사분면에 존재    
        map[a+len][b+len] = map[a+len][b+len-1] = map[a+len-1][b+len] = cnt++;
    }else if(y<len+a && x>=len+b){  //2
        map[a+len][b+len] = map[a+len][b+len-1] = map[a+len-1][b+len-1] = cnt++;
    }else if(y>=len+a && x<len+b){  //3
        map[a+len][b+len] = map[a+len-1][b+len] = map[a+len-1][b+len-1] = cnt++;
    }else{  //4
         map[a+len-1][b+len] = map[a+len][b+len-1] = map[a+len-1][b+len-1] = cnt++;
    }
    
}
int main()
{
    int k, x, y;
    cin >> k >> x >> y;
    putTile(0, 0, k,  x-1, y-1);
    int len = 1<<k;
    map[x-1][y-1] = -1;

    cout << endl;
    for(int i=len-1; i>=0;i--){
        for(int j=0; j<len;j++)
            cout <<map[j][i] <<" ";
        cout << endl;
    }
    return 0;
}
