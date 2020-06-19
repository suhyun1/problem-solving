#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//문자열 모두 소문자로 변환하는 함수
string toLowerCase(string str){
    for(int i=0;i<str.size();i++){
        if( str[i] >='A' && str[i] <='Z')
            str[i] = str[i] - ('A'-'a');
    }
    return str;
}

int solution(string str1, string str2) {
    vector<string> set1,set2;
    str1 = toLowerCase(str1);
    str2 = toLowerCase(str2);
    
    for(int i=0;i<str1.size()-1;i++){
        if(str1[i] >= 'a' && str1[i]<= 'z' && str1[i+1] >= 'a' && str1[i+1]<= 'z')
            set1.push_back(str1.substr(i,2));
    }
    
    for(int i=0;i<str2.size()-1;i++){
        if(str2[i] >= 'a' && str2[i]<= 'z' && str2[i+1] >= 'a' && str2[i+1]<= 'z')
            set2.push_back(str2.substr(i,2));
    }
    
    if(set1.size()==0 && set2.size()==0)    //모두 공집합일 경우 자카드 유사도 1로 정의
        return 65536;
    
    //set_union과 set_intersection 연산 이전 정렬 필요
    sort(set1.begin(), set1.end());
    sort(set2.begin(), set2.end());
    
    vector<string> union_set, intersect_set;
    set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), back_inserter(union_set));
    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), back_inserter(intersect_set));
    
    double jaccard  = (double)intersect_set.size()/union_set.size();
    
    return jaccard*65536;
}