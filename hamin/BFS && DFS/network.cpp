#include <string>
#include <vector>

using namespace std;

bool connected[200];    // 연결된 컴퓨터는 true값을 가짐.

void dfs(int n, int i, vector<vector<int>> &computers) {
    connected[i] = true;
    
    for (int j = 0; j < n; j++) {
        if ((computers[i][j] == 1) && (i != j)) {
            computers[i][j] = 0;    // 연결을 확인한 컴퓨터는 배열 값을 0으로 바꿈.
            dfs(n, j, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int network = 0;
    int notConnected = 0;
    
    // 배열 초기화
    for (int t = 0; t < n; t++)
        connected[t] = false;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // 연결되어 있다면.
            if (computers[i][j] == 1) {
                computers[i][j] == 0;
                connected[i] = true;
                network++;
                dfs(n, j, computers);
            }
        }
    }
    // 연결되지 않은 컴퓨터 개수 확인.
    for (int k = 0; k < n; k++){
        if (connected[k] == false)
            notConnected++;
    }
    return network + notConnected;
}
