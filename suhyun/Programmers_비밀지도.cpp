#include <string>
#include <vector>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i=0; i<arr1.size();i++){
        arr1[i] = arr1[i] | arr2[i];
        int tmp = arr1[i];
        string line = "";
        for(int j=0; j<n;j++){
            if(tmp & 1)
                line = '#' + line;
            else
                line = ' '+ line;
            tmp >>= 1;
        }
        answer.push_back(line);
    }
   
    return answer;
}