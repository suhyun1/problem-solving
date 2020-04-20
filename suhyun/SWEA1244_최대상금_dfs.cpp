#include<iostream>
#include<string>
 
using namespace std;
 
string numArr;
int maxNum;
 
void dfs( int index, int changeCnt){
    if(changeCnt == 0){
        int number = stoi(numArr);
        if(number > maxNum){
            maxNum = number;
        }
        return;
    }
     
    for(int i=index; i<numArr.length()-1;i++){
        for(int j=i+1; j<numArr.length();j++){
            if(numArr[i] <= numArr[j] ){
                int temp = numArr[j];
                numArr[j] = numArr[i];
                numArr[i] = temp;

                dfs( i, changeCnt-1);

                temp = numArr[j];
                numArr[j] = numArr[i];
                numArr[i] = temp;
            }
        }
    }
 
     
}
int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
 
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int number, changeCnt; 
        cin >> number >> changeCnt;
        maxNum = number;
        numArr = to_string(number);
        dfs( 0,changeCnt);
        cout << "#"<< test_case << " " << maxNum << endl;
 
    }
    return 0;