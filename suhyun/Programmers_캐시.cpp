#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    if(cacheSize==0){
        return 5*cities.size();
    }
    vector<string> cache;
    for(int i=0; i<cities.size();i++){
        //소문자변환
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
        bool flag = false;
        for(int j=0; j<cache.size();j++){
            if(cities[i] == cache[j]){  //hit
                cache.erase(cache.begin()+j);
                cache.push_back(cities[i]);
                answer += 1;
                flag = true;
                break;
            }
        }
        if(!flag){  //miss
            if(cache.size() >= cacheSize)
                cache.erase(cache.begin());
            cache.push_back(cities[i]);
            answer += 5;
        }
    }
    return answer;
}