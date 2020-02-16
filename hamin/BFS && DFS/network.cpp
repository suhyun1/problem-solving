#include <string>
#include <vector>

using namespace std;

bool connected[200];    // 각각의 컴퓨터가 연결 되었는지 아닌지 나타내는 배열.

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
    for (int i = 0; i < n; i++)
        connected[i] = false;
    
    for (int i = 0; i < n; i++) {
        // 다 할 필요 없이 i+1 ~ n-1까지.
        for (int j = i + 1; j < n; j++) {
            // 연결되어 있다면.
            if (computers[i][j] == 1) {
                connected[i] = true;    // 연결 되어있음 표시.
                network++;
                dfs(n, j, computers);   // j와 연결된 것들은 같은 네트워크이기 때문에 dfs로 computers[i][j] = 0으로 바꿔줌.
            }
        }
    }
    // 연결되지 않은 컴퓨터 개수 확인.
    for (int i = 0; i < n; i++){
        if (connected[i] == false)
            notConnected++;
    }
    return network + notConnected;
}
