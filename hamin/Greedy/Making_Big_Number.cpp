#include <string>

using namespace std;

string solution(string number, int k) {
    string answer = number;

    int index = 1;

    if (answer.length() == k)
        return "";

    while (k > 0)
    {
        for (; index < answer.length(); index++)
        {
            char beforeChr = answer[index - 1];
            char currentChr = answer[index];

            if (beforeChr < currentChr)
            {
                answer.erase(--index, 1);

                if (index < 1)
                    index = 1;

                k--;

                break;
            }
        }

        if (index == answer.length())
        {
            while (k > 0)
            {
                answer.erase(--index, 1);

                index--;

                k--;
            }

            break;
        }
    }

    return answer;
}