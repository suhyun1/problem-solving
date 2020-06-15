#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string word){

    bool flag = true;
    int len = word.length();
    for(int i=0; i<len/2;i++){
        if(word[i] != word[len-i-1]){
            flag = false;
            break;
        }
    }
    return flag;
}
int main(){
    string word;
    cin >> word;
    cout << isPalindrome(word) << endl;

}