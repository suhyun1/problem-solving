#include<iostream>

using namespace std;

int main(void){
    int testCase;
    for (int t = 1; t <= 10; t++){
        int n;
        int cnt = 0;
        int check = 1;

        cin >> n;
        char board[8][8];
        
        // 가로
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8-n+1; j++) {
                int l, r;
                l = j; r = n - 1 + j;
                while (l <= r){
                    if (board[i][l] != board[i][r]){
                        check = 0;
                        break;
                    }
                    l++;
                    r--;
                }
                if (check != 0){
                    cnt++;
                }
                check = 1;
            }
        }

        // 세로
        for (int i = 0; i < 8; i++){
            for (int j = 0; j < 8-n+1; j++){
                int nor, s;
                nor = j;
                s = n - 1 + j;
                while (nor <= s){
                    if (board[nor][i] != board[s][i]){
                        check = 0;
                        break;
                    }
                    nor++;
                    s--;
                }
                if (check != 0){
                    cnt++;
                }
                check = 1;
            }
        }
        cout << "#" << t << ' ' << cnt << endl;
    }
    return 0;
}