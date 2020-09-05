#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string to_upper(string str){
    for(int i=0; i<str.length();i++){
        char tmp = str[i];
        if(tmp>='A' && tmp<='Z')
            str[i] = tmp + 'a'-'A';
    }
    return str;
}
    
bool cmp(const vector<string>& a, const vector<string>& b){
    if(to_upper(a[0]) == to_upper(b[0])){   //head 사전순비교
        if(stoi(a[1]) == stoi(b[1]))   //number비교
            return false;
        else
            return stoi(a[1]) < stoi(b[1]);
    }else
        return to_upper(a[0]) < to_upper(b[0]);
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    //head, number, tail 구분하기
    vector<vector<string> > split(files.size(), vector<string> (3));
    for(int i=0; i<files.size();i++){
        int j=0; 
        while(j<files[i].size()){   //head
            if(files[i][j]<'0' || files[i][j]>'9')
                split[i][0] += files[i][j];
            else
                break;
            j++;
        }
        while(j<files[i].size()){   //number
            if(files[i][j]>='0' && files[i][j]<='9' && split[i][1].length()<=5 )
                split[i][1] += files[i][j];
            else 
                break;
            j++;
        }
        split[i][2] = files[i].substr(j);   //tail
    }
    
    stable_sort(split.begin(), split.end(), cmp);
    
    for(int i=0; i<split.size();i++){
        answer.push_back(split[i][0]+split[i][1]+split[i][2]);
    }
    return answer;
}