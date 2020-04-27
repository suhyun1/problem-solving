#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T=10;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int test_num;
        cin >> test_num;
        
        int map[100][100];
        for(int i=0; i<100;i++){
            for(int j=0;j<100;j++){
                cin >> map[i][j];
            }
        }
        
        int loc;
        for(int i=0; i<100;i++){
            if(map[99][i] == 2)
                loc = i;
        }
		int cur_x=loc-1, cur_y=98;
        int dir = 0; //방향
        while(cur_y>0){
            if(dir==0){	 //위로
                if(cur_x-1 >=0 && map[cur_y][cur_x-1] == 1){
                	dir = 2;
                    cur_x --;
            	}else if(cur_x+1 <100 && map[cur_y][cur_x+1] == 1){
                	dir = 1;
                    cur_x ++;
            	}else{
                    cur_y--;
                }
            }else if(dir==1){	//오른쪽 이동
                if(map[cur_y-1][cur_x] == 1){
                	dir = 0;
                    cur_y --;
            	}else{
                    cur_x++;
                }
            }else if(dir==2){	//왼쪽 이동
                if(map[cur_y-1][cur_x] == 1){
                	dir = 0;
                    cur_y --;
            	}else{
                    cur_x--;
                }
            }
        
        }
		cout <<"#"<<test_case<< " "<< cur_x << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}