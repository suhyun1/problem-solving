#include<iostream>
using namespace std;

int magnet[4][8];

void rotate(int n, int d){
    if(d == 1){	//시계방향
        int tmp = magnet[n][7];
        for(int j=7; j>=1; j--){
            magnet[n][j] = magnet[n][j-1];
        }
        magnet[n][0] = tmp;
    }else{
        int tmp = magnet[n][0];
        for(int j=0; j<=6; j++){
            magnet[n][j] = magnet[n][j+1];
        }
        magnet[n][7] = tmp;
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int K; //회전수
        cin >> K;
        for(int i=0;i<4;i++){
            for(int j=0;j<8;j++)
                cin >> magnet[i][j];
        }
        int no, direction;
        for(int i=0; i<K;i++){
            cin >> no >> direction;
            no--;
            int east = magnet[no][2];
            int west = magnet[no][6];
            rotate(no, direction);
            int cur_direction = direction;
            int j=no+1;
            //오른쪽
            while(j < 4 && east != magnet[j][6]){
                east = magnet[j][2];
                cur_direction= -cur_direction;
                rotate(j, cur_direction);
                j++;
            }
            //왼쪽
            cur_direction = direction;
            j=no-1;
            while(j >=0 && west != magnet[j][2]){
                west = magnet[j][6];
                cur_direction= -cur_direction;
                rotate(j, cur_direction);
                j--;
            }   
        }
         
        int ans = 0;
        int sum = 1;
        for(int i=0; i<4;i++){
            if(magnet[i][0] == 1)
            	ans += sum;
            sum *=2 ;
        }
     
        cout << "#" << test_case << " " << ans << endl;
        
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}