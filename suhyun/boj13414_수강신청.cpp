#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

/*
1. map에 차례로 (학번, 순서)쌍 삽입 (순서는 뒷 번호로 업데이트)
2. vector로 변환하여 value(순서) 순으로 정렬
3. K만큼 출력

주의할 점은 대기목록의 길이 제한 1 ≤ L ≤ 500,000 으로 시간 초과 조심
*/

bool cmp(const pair<string, int>& a, const pair<string, int>& b){
    return a.second < b.second;
}

int main(){
    int K, L;
    scanf("%d %d", &K, &L);
    map<string, int> m;
    string tmp;
    for(int i=0; i<L;i++){
        cin >> tmp;
        m[tmp] = i+1;
    }
    vector<pair<string, int> > vec;
    map<string, int> :: iterator it;
    for(it=m.begin();it!=m.end();it++){
        vec.push_back(make_pair(it->first, it-> second));
    }

    sort(vec.begin(), vec.end(), cmp);
    
	//시간초과로 인해 endl -> "\n" 		
    for (int i = 0; i < vec.size(); i++) {
        if(i > K-1)
            break;
        cout << vec.at(i).first << "\n";
    }
    
    return 0;
}