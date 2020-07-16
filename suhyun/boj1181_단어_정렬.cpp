#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string &a, const string &b){
    if(a.size() == b.size()){
        return a < b;
    }
    return a.size() < b.size();
}
int main()
{
    int N;
    cin >> N;
    vector<string> words(N);
    for(int i=0; i<N;i++)
        cin >> words[i];
    
    sort(words.begin(), words.end(), cmp);

        
    //중복처리
    string tmp = "";
    for(int i=0; i<N;i++){
        if(tmp == words[i]) continue;
        cout << words[i] <<endl;
        tmp = words[i];
    }
    

    return 0;
}
