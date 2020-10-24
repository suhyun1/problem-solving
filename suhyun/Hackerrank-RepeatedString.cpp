#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    int countA = 0;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == 'a')
            countA++;
    
    int lastSubStr = n % s.length();
    long repeatCount = n / s.length();

    if (lastSubStr == 0){
        return countA * repeatCount;
    } else {
        int subCountA = 0;
        for (int i = 0; i < lastSubStr; i++) {
            if(s[i] == 'a')
                subCountA++;
        }
        return countA * repeatCount + subCountA; 
    }

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
