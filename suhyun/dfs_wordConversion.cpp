#include <string>
#include <vector>

using namespace std;

bool visited[51];
int answer = 51;
void dfs(string begin, string target, vector<string> words, int depth ){
  
    for(int i=0; i<words.size();i++){
        if(visited[i])
            continue;
        int cmp_count = 0;
        for(int j=0;j< words[i].size();j++){
            if( begin[j]!=words[i][j])
                cmp_count++;
        }
        if(cmp_count==1){
            
            if(words[i]==target && depth < answer)   {
                
                answer = depth;
                return;
            } 
            visited[i] = true;
            dfs(words[i], target, words, depth+1);
            visited[i] = false;
        }    
        
    }
}
int solution(string begin, string target, vector<string> words) {
    
    
    dfs(begin, target, words, 1);
    if(answer == 51)    return 0;
    else return answer;
}