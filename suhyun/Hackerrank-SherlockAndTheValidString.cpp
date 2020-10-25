#include <bits/stdc++.h>
using namespace std;

// Complete the isValid function below.
string isValid(string s) {
    vector<int> count(26, 0);
    for (auto c : s) {
        count[c - 'a']++;
    }
    
    sort(count.begin(), count.end());
    int max = count[25];
    int min = 0;
    int i;
    for(i = 0; i < 26; i++)
        if(count[i] > 0){
            min = count[i];
            break;
        }
            
    if(min == max)
        return "YES";
    else if ((max - 1 == min && max != count[24]) || (min == 1 && count[i + 1] == max))
        return "YES";
    else 
        return "NO";
 
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
