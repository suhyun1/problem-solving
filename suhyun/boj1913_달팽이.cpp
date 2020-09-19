#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, search;
    cin >> N >> search;
    
    int arr[1000][1000];
    int start_x = N / 2;
    int start_y = N / 2;
    int number = 1;
    arr[start_x][start_y] = number++;
    int count = 1;
    bool flag = false;
    while(1){
        //up
        for(int i=0; i<count; i++){
            arr[--start_x][start_y] = number++;
            if(start_x == 0 && start_y == 0){
                flag = true;
                break;
            }
        }
        if(flag)
                break;
        //right
        for(int i=0; i<count; i++){
            arr[start_x][++start_y] = number++;
        }
        count++;
        //down
        for(int i=0; i<count; i++){
            arr[++start_x][start_y] = number++;
        }
        
        //left
        for(int i=0; i<count; i++){
            arr[start_x][--start_y] = number++;
        }
        count++;
    
    }
    int x_pos, y_pos;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << arr[i][j] << " ";
            if(arr[i][j] == search){
                x_pos = i+1;
                y_pos = j+1;
            }
        }
        cout << endl;
    }
    cout << x_pos <<" " << y_pos <<endl;

    return 0;
}
