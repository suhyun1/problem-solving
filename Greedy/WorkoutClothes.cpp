#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int student[31];

    for (int i = 1; i < n+1; i++) {
        student[i] = 1;
    }

    for (auto &r : reserve) {
        student[r] ++;
    }

    for (auto &l : lost) {
        student[l] --;
    }

    for (int i = 1; i < n+1; i++) { // 모든 학생 검사
        
        if (student[i] > 1) { // 두 벌 옷 이상 가진사람이 있다면
            if (i != 0) {
                if (student[i - 1] == 0) {  // 앞사람 확인해서 없으면 줘.
                    student[i - 1]++;
                    student[i]--;   // 줬다면 이제 다음 애를 확인
                    continue;
                }
            }
            // 앞사람이 없을경우
            if (i != n) {   
                if (student[i + 1] == 0) {  // 뒷사람을 확인
                    student[i + 1]++;   // 뒷사람 확인해서 없으면 줘
                    student[i]--;
                }
            }
        }
    }

    for (int i = 1; i < n+1; i++) {
        if (student[i] != 0) {
            answer++;
        }
    }


    return answer;
}
