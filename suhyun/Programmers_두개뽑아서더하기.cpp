#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int visited[201] = {false, };
    for(int i=0; i<numbers.size(); i++){
        for(int j=i+1; j<numbers.size(); j++){
            visited[numbers[i]+numbers[j]] = true;
        }
    }
    
    for(int i=0; i<201; i++)
        if(visited[i])
            answer.push_back(i);
    
    return answer;
}