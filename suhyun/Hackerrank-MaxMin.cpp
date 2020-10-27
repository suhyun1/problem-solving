#include <bits/stdc++.h>

using namespace std;

// Complete the maxMin function below.
// arr 정렬
// arr를 K개씩 묶어보면서 max - min값 비교할 것
int maxMin(int k, vector<int> arr) {
    int minUnfairness = 1000000000;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size() - k + 1; i++) {
        int minValue = arr[i];
        int maxValue = arr[i + k - 1];
        if (minUnfairness > maxValue - minValue)
            minUnfairness = maxValue - minValue;
    }

    return minUnfairness;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    int result = maxMin(k, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
