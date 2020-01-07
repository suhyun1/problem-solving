#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    // 비교할 전화번호 중 앞의 것
    for(int i=0; i<phone_book.size(); i++){
        // 비교할 전화번호 중 뒤의 것
        for(int j=i+1; j<phone_book.size(); j++){
            // 뒤의 것이 더 길거나 같다면
            if(phone_book[i].size() <= phone_book[j].size()){
                // 앞의 것의 길이만큼 두 전화번호를 비교
                if(phone_book[i] == phone_book[j].substr(0,phone_book[i].size()))
                    return false;
            }
            // 앞의 것이 더 길거나 같다면
            // 뒤의 것의 길이만큼 두 전화번호를 비교
            if(phone_book[j] == phone_book[i].substr(0,phone_book[j].size()))
                return false;
        }
    }
    return true;
}