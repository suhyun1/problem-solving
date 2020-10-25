#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {
    int deletedNum = 0;
    int alphabetCount[26] = {0, };
    
    for (auto c : a) {
        alphabetCount[c - 'a']++;
    }
    for (auto c : b) {
        alphabetCount[c - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
        if (alphabetCount[i] != 0)
            deletedNum += abs(alphabetCount[i]);
    }
    return deletedNum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
