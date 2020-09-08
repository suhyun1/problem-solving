#include <vector>

using namespace std;

int size_of_one_area;
int M, N;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int x, int y, vector<vector<int>>& picture, vector<vector<bool>>& visited,int area_color){
    
    for(int i=0; i<4;i++){
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        if(next_x>=0 && next_x<M && next_y>=0 && next_y<N){
            if(picture[next_x][next_y] == area_color&& !visited[next_x][next_y]){
                size_of_one_area++;
                visited[next_x][next_y] = true;
                bfs(next_x, next_y, picture, visited, area_color);
            }
        }
    }
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    vector<vector<bool>> visited(m, vector<bool>(n));
    M = m;
    N = n;
    
    for(int i=0; i<m;i++){
        for(int j=0; j<n;j++){
            if(picture[i][j] != 0 && !visited[i][j]){
                visited[i][j] = true;
                number_of_area++;
                size_of_one_area = 1;
                bfs(i, j, picture, visited, picture[i][j]);
                max_size_of_one_area = max(max_size_of_one_area, size_of_one_area);
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}