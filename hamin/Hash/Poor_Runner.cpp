#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {

    int size = completion.size();

    map<string, int> name;
    int* num = new int[size];
    for(int i=0 ; i<size ; i++)
    {
        num[i] = 1;
    }

    //completion으로 명단 작성
    map<string, int>::iterator it;
    for(int i=0 ; i<size ; i++)
    {
        it = name.find(completion[i]);
        if(name.count(completion[i]) == 0)
            name.insert(pair<string, int>(completion[i], i));
        else //이미 있으면 인원 추가
            num[it->second]++;
    }

    //participant로 명단과 대조하여 체크
    for(int i=0 ; i<size+1 ; i++)
    {        
        if(name.count(participant[i]) == 0) //명단에 없으면 바로 출력
            return participant[i];
        else //명단에 있으면
        {
            it = name.find(participant[i]);

            if(num[it->second] <= 0)
                 return participant[i];
            else
                 num[it->second]--;
        }
    }

    return "";
}