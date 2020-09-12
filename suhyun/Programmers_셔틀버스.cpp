#include <string>
#include <algorithm>
using namespace std;

string convertToString(int time){
    string hour = to_string(time / 60);
    string min = to_string(time % 60);
    if(hour.length() == 1) hour = "0" + hour;
    if(min.length() == 1) min = "0" + min;
    return hour + ":" + min;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<int> time(timetable.size());
    for(int i = 0; i < timetable.size(); i++){
        time[i] = stoi(timetable[i].substr(0,2)) * 60 + stoi(timetable[i].substr(3));
    }
    sort(time.begin(), time.end());
    
    int waiting_count = 0;
    int bus_arrival = 540;
    int bus_count = 0;
    int i = 0;
    while(n > bus_count){
        while(i < time.size()){
            if(waiting_count < m && time[i] <= bus_arrival){
                waiting_count++;
                i++;
            }
            else 
                break;
        }
        bus_count++;
        if( n == bus_count ){
            if(waiting_count < m)
                answer = convertToString(bus_arrival);
            else
                answer = convertToString(time[i-1]-1);
            break;
        }
        bus_arrival += t;
        waiting_count = 0;
    }
    return answer;
}