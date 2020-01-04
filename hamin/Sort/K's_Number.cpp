#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer; int a[3];
    vector<int> row;

    for(int i=0; i<commands.size(); i++)
    {
        for(int j=0; j<3; j++)
        {
             a[j] = commands[i][j];      // 2,5,3 저장
        }
        for(int i=a[0]-1; i<=a[1]-1; i++)
        {
            row.push_back(array[i]);    // 인덱스 1부터 4까지 배열 저장
        }
        sort(row.begin(), row.end());   // row배열 정렬하기
        
        int k = a[2] - 1;   // 정렬한 후 숫자 찾기
        answer.push_back(row[k]);
        row.clear();   // row 벡터 초기화
    }
    return answer;
}