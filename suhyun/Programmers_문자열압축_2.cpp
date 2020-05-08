#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    int min_length = s.length();
    for(int i=1; i<=s.length()/2;i++){  //i:문자열 자르는 단위
        vector<string> split;
        for(int j=0;j<s.length();j+=i){
            split.push_back(s.substr(j,i));
        }
        
        string compress ="";
        int compress_length = 0;
        int repeat = 1;
        string prev = split[0];
        for(int j=1;j<split.size();j++){
            if(prev == split[j]){
                repeat++;
            }else{
                if(repeat != 1)    
                    compress_length += to_string(repeat).length();
                compress_length += i;
                prev = split[j];
                repeat = 1;
            }
            
            if(j==split.size()-1){
                if(repeat == 1)    
                    compress_length += split[j].length();
                else 
                    compress_length += i + to_string(repeat).length();
            }
                
        }
        if(min_length > compress_length)
            min_length = compress_length;
        
    }
    
    return min_length;
}