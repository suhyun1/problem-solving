#include <string>
#include <vector>
#include <iostream>

#define MAX 101

using namespace std;

int route[MAX][MAX] = {0, };  // 경로 수를 저장.
int pond[MAX][MAX] = {0, };   // 웅덩이 위치 저장.

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer;

    // pond가 나오면 1로 초기화.
    for (int i = 0; i < puddles.size(); i++) {
        pond[puddles[i][1]-1][puddles[i][0]-1] = 1;
    }

    // 집에서 경로 1로 출발.
    route[0][0] = 1;

    // 배열 순회.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 첫 출발지면 continue
            if (i == 0 && j == 0){
                continue;
            }

            // pond가 나오면 경로 0개.
            if (pond[i][j] == 1) {
                route[i][j] = 0;
            } else {
                // 윗쪽 가장자리일 경우 바로 왼쪽 경로 받아오기.
                if(i == 0) {
                    route[i][j] = route[i][j-1];
                }

                // 왼쪽 가장자리일 경우 바로 윗 경로 받아오기.
                else if(j == 0) {
                    route[i][j] = route[i-1][j];
                }

                // 가운데 부분일 경우 윗, 왼쪽 경로 합해서 나머지 구하기.
                else {
                    route[i][j] = (route[i-1][j] + route[i][j-1]) % 1000000007;
                }
            }
        }
    }
    answer = route[n-1][m-1];

    return answer;
}
