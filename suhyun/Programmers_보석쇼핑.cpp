#include <string>
#include <vector>
#include <map>

using namespace std;

/*
map에 보석별 개수 저장
left, right포인터로 범위 이동해가며 보석 종류 비교
해당 범위에서 보석 종류 모자라면 => right 한칸 이동
보석 종류 같다면 => left 한칸 이동 (이때 더 좁은 범위면 업데이트)
*/
vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    
    map<string, int> total; //보석 종류 개수 
    for(int i=0; i<gems.size();i++){
        total[gems[i]]++;
    }
    
    map<string,int> m;
    answer[0] = 1;
    answer[1] = gems.size();
    int i=0;    //left
    int j=0;    //right
    int diff = gems.size();
    while(1){
        if(m.size() == total.size()){
            if(diff > j-i )  {    //더 좁은 범위면 갱신
                diff = j-i;
                answer[0] = i+1;
                answer[1] = j;
            }
            if(m[gems[i]]==1)
                m.erase(gems[i]);
            else if(m[gems[i]]>1)
                m[gems[i]]--;
            i++;
        }else if (j==gems.size()){
            break;
        }else if(m.size() < total.size()){  //모든 종류가 포함되지 않으면
            m[gems[j]]++;
            j++;
        }
    }


    return answer;
}