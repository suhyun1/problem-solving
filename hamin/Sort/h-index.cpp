#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
  sort(citations.begin(), citations.end(), greater<int>()); // 내림차순 정렬.
  
  for(int i = 0; i < citations.size(); i++){
    if(citations[i] < i + 1)    // citation[i]번 이상 인용 된 논문이 i편 이고(i번째 인자 이니까), 나머지 논문은 citation[i]번 이하 인용(내림차순 정렬 이니까)되었다.
      return i; // H-index는 i이다.
  }
}
