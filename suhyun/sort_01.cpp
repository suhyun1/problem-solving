#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<int> insertionSort(vector<int> array){
    
    int tmp, i, j;
    for(i=1;i<array.size();i++){
        tmp = array[i];
        j = i -1;
        while(j>=0 && array[j]>tmp){
            array[j+1]  = array[j];
            j--;
        }
        array[j+1] = tmp;
    }
    
    return array;
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    int i,j,k;
    for(int n=0;n<commands.size();n++){
        i = commands[n][0];
        j = commands[n][1];
        k = commands[n][2];
        
        vector<int> sub_array, sorted_array;
        for(int m=i-1;m<j;m++){
            sub_array.push_back(array[m]);
        }

        //삽입정렬
        sorted_array = insertionSort(sub_array);
        
        answer.push_back(sorted_array[k-1]);
            
    }
    return answer;
}