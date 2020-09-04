#include <string>
#include <vector>
using namespace std;

//key를 90도씩 회전하고 -> 상하좌우로 옮겨가면서 lock과 비교(key+lock = 1일때 잠금 해제!)

int key_size, lock_size,map_size;

//오른쪽으로 90도씩 회전하는 함수
void rotate(vector<vector<int>>& key){
    int size = key.size();
    vector<vector<int>> tmp(size, vector<int>(size));
    for(int i=0; i<size;i++){
        for(int j=0;j<size;j++){
            tmp[i][j] = key[size-j-1][i];
        }
    }
    key = tmp;
}

//주어진 위치에서 key가 lock을 모두 채우는지 확인하는 함수
bool unlock(int start_x, int start_y, vector<vector<int>>& key, vector<vector<int>> map){
    for(int i=0;i<key_size;i++){
        for(int j=0;j<key_size;j++){
            map[start_x+i][start_y+j] += key[i][j];
        }
    }
    
    //lock다 채워졌는지 확인
    for(int i=lock_size;i<lock_size*2;i++){
        for(int j=lock_size;j<lock_size*2;j++){
            if(map[i][j] != 1)
                return false;
        }
    }
    
    return true;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    
    key_size = key.size();
    lock_size = lock.size();
    map_size = lock_size *3;
    vector<vector<int>> lock_map (map_size, vector<int> (map_size,0));
    //map중간에 lock놓기
    for(int i=0; i<lock_size;i++){
        for(int j=0;j<lock_size;j++)
            lock_map[lock_size+i][lock_size+j] = lock[i][j];
    }
    
    int n=0;
    while(n<4){
        for(int i=0;i<map_size-key_size;i++){
           for(int j=0;j<map_size-key_size;j++){
                if(unlock(i, j, key, lock_map)){
                    return true;
                }
            } 
        }
        rotate(key);
        n++;
    }
    
    return false;
}