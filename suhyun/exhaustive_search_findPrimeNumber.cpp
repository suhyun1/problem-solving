//7점
#include <string>
#include <vector>
#include <algorithm>


using namespace std;
bool checkNum(int i, string numbers){
    vector<int> visited(numbers.length());
    bool flag = false;
    while(i>0){
        flag = false;
        int tmp = i%10;
        for(int j=0;j<= numbers.length();j++){
            if(tmp == numbers[j]-'0' && !visited[j]){
                flag = true;
                visited[j] = true;
                break;
            }
        }
        if(!flag)
            return false;
        i = i/10;
    }
    return true;
}
int solution(string numbers) {
    int answer = 0;
    
    sort(numbers.begin(), numbers.end(), greater<int>());
    int max = stoi(numbers);
    
    vector<bool> prime(max+1);

    for(int i=2;i<=max;i++){
        if(!prime[i] && checkNum(i, numbers)){
            answer++;
        }
        if(!prime[i]){
            for(int j=i; j<=max; j+=i){
                prime[j] = true;
            }
        }
    }
    
   
    return answer;
}


