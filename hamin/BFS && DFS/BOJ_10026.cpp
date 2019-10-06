#include <iostream>
#include <string>

using namespace std;

int n;  //n은 줄의 갯수.
int count1 = 0, count2 = 0; //count1은 정상인, count2는 색약.
int b = 0;
char arr[101][101];
bool visit[101][101];

void BFS(int x, int y)
{
    b++;
    visit[x][y] = true; // 방문했다고 표시.
    // 상
    if (arr[x + 1][y] == '1' && x + 1 < n && visit[x + 1][y] == false){
        BFS(x + 1, y);
    }
    // 하
    if (arr[x - 1][y] == '1' && x - 1 < -1 && visit[x - 1][y] == false){
        BFS(x - 1, y);
    }
    // 좌
    if (arr[x][y - 1] == '1' && y - 1 < -1 && visit[x][y - 1] == false){
        BFS(x, y - 1);
    }
    // 우
    if (arr[x][y + 1] == '1' && y + 1 < n && visit[x][y + 1] == false){
        BFS(x , y + 1);
    }
}

/*
// 영역의 갯수를 구해주는 DFS.
void DFS(int **arr, int num, int x, int y){
    arr[y][x] = 0;
    if(y>0 && arr[y-1][x] == num)
        DFS(arr, num, x, y-1);
    if(y<n-1 && arr[y+1][x] == num)
        DFS(arr, num, x, y+1);
    if(x>0 && arr[y][x-1] == num)
        DFS(arr, num, x-1, y);
    if(x<n-1 && arr[y][x+1] == num)
        DFS(arr, num, x+1, y);
}
*/

int main(){
    string str;
    cin >> n;
    int **arr1 = new int*[n], **arr2 = new int*[n];

    for (int i = 0; i < n; i++){
        arr1[i] = new int[n];
        arr2[i] = new int[n];
    }

    //입력받을 때 2가지 배열로 나누어 입력받는 코드.
    for (int i = 0; i < n; i++){
        cin >> str;
        for (int j = 0; j < n; j++){
            switch (str[j]){
                case 'R':
                    arr1[i][j] = 1;
                    arr2[i][j] = 1;
                    break;
                case 'G':
                    arr1[i][j] = 2;
                    arr2[i][j] = 1;
                    break;
                case 'B':
                    arr1[i][j] = 3;
                    arr2[i][j] = 2;
                    break;
            }
        }
    }

    /*
    // DFS 실행하여 블럭의 수 세기.
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (arr1[i][j] != NULL){
                count1++;
                DFS(arr1, arr1[i][j], j, i);
            }
            if (arr2[i][j] != NULL){
                count2++;
                DFS(arr2, arr2[i][j], j, i);
            }
        }
    }
    */

    // BFS 실행하여 블럭의 수 세기. 
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            b = 0;
            if (arr1[i][j] == '1' && visit[i][j] == false){
                count1++;
                BFS(i, j);
            }
            if (arr2[i][j] == '1' && visit[i][j] == false){
                count2++;
                BFS(i, j);
            }
        }
    }
    cout << count1 << " "<< count2 << endl;
    return 0;
}