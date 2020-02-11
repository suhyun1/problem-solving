//11점
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 1000000000000000;
    
    sort(times.begin(), times.end());
    int size = times.size();
    long long start = 0;
    long long end = (long long)times[size-1] * n;   //최대값은 가장 오래걸리는 심사관이 n명을 모두 심사할 경우 (연산시 type 주의!)

    while(start <= end){
        long long mid = (start + end)/2;
        
        long long people_cnt = 0; //처리할 수 있는 사람 수
        for(int i=0; i<size;i++){
            people_cnt += mid /times[i];
        }
        
        if(people_cnt < n){
            start = mid+1;
        }else{
            if(mid < answer){
                answer = mid;
            }
            end = mid-1;
        }
    }
    return answer;
}