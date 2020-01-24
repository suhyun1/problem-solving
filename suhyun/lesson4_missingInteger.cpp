#include <vector>
#include <map>


int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    map<int, bool> m;
    
    for(auto a : A){
        if(a > 0 )
            m.insert(pair<int, bool>(a, true));
    }
    
    int index = 1;
    for(auto it = m.begin();it!=m.end();it++){
        
        if(it->first != index)
            return index;
        index++;
    }
    
    return index;
}