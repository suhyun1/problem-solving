//9점
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> budgets, int M) {
    int answer = 0;
    int max = 0;    //budgets중 최대값
    
    //총합이 M 이하인 경우
    long sum = 0;   //**예산총합 최대 100000*100000으로 long사용**
    for(int i=0;i<budgets.size();i++){
        sum += budgets[i];
        if(max < budgets[i] )
            max = budgets[i];
    }
    if(sum <= M){
        return max;
    }
    
    //총합이 M 초과하는 경우
    int start = 0;
    int end = max;
    int mid;
    int max_total = 0;
    int limit =0;   //상한선
    
    while(end >= start){
        mid = (start+end)/2; 

        //mid가 상한선일때 total budget구함
        int total = 0;
        for(int b : budgets){
            b > mid ? total += mid : total += b;
        }
        
        if(total > M){
            end = mid-1;
        }else if(total < M){   //정답 가능성 있으므로 저장
            start = mid+1;
            
            if(total > max_total){
                max_total = total;
                limit = mid;
            } 
        }else
            return mid;
   
    }
    
    return limit;
}