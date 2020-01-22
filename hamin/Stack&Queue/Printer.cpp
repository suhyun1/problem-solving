#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) 
{
    vector<int> temp = priorities;
    sort(temp.begin(), temp.end(), greater<int>());
    int answer = 0;
    int start = 0;
    int end = priorities.size() - 1;
    bool is_printed = false;

    int i = 0;

    while (!is_printed)
    {
        if (temp[answer] == priorities[start])
        {
            answer += 1;

            if (start == location)
                is_printed = true;
        }
        else
        {
            end = start;
        }

        start = (start + 1) % priorities.size();
    }

    return answer;
}