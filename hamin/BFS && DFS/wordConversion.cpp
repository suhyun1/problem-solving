#include <string>
#include <vector>

using namespace std;

vector<bool> check; // 탐색한 단어 재탐색하지 않도록 처리.
int answer = 51;    // 50개 이하의 단어 이므로 가장 큰 경우(50) 대비해 51로 세팅.

void dfs(vector<string> words, string now, string target, int depth) {
    // 완성 비교.
    if (now.compare(target) == 0){
        answer = min(answer, depth);  // answer와 depth 중 작은 값을 answer에 넣기.
        return;
    }
    
    // words의 각 단어 마다 비교.
    for (int i = 0; i < words.size(); i++) {
        // now와 words의 단어가 하나만 다르면 변경 가능.
        int diff = 0;   // 몇개의 스펠링이 다른지 나타내는 diff.
        if (check[i] == true)   // 탐색했던 단어라면 재탐색 하지 말기.
            continue;
        
        // 스펠링 몇개가 다른지 판별.
        for (int j = 0; (j < now.size())&&(diff <= 1); j++) {
            if (now[j] != words[i][j])
                diff++;
        }
             
        // 스펠링 하나만 다르다면 변경.
        if (diff == 1) {
            check[i] = true;    // 탐색했음 표시.
            dfs(words, words[i], target, depth+1);
            check[i] = false;   // 탐색 끝.
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    check.assign(words.size(), false);  // 벡터 check를 모두 false로 초기화.
    dfs(words, begin, target, 0);
    // 변환할 수 없는 경우.
    if (answer == 51)
        return 0;
    
    return answer;
}
