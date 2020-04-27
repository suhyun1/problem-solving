#include <iostream>

using namespace std;

int main(void) {
    int test_case = 10;

    for (int i = 1; i <= test_case; i++) {
        int n;
        cin >> n;
        int arr[1001] = { 0, };
        for (int j = 0; j < n; j++){
            int tmp;
            cin >> arr[j];
        }
        long long sum = 0;

        for (int k = 2; k < n - 2; k++) {
            int left1 = arr[k - 2];
            int left2 = arr[k - 1];
            int right1 = arr[k + 1];
            int right2 = arr[k + 2];

            int min = 2e9;
            if (arr[k] - left1 <= 0 || arr[k] - left2 <= 0 || arr[k] - right1 <= 0 || arr[k] - right2 <= 0) {
                continue;
            }
            if (arr[k] - left1 < min){
                min = arr[k] - left1;
            }
            if (arr[k] - left2 < min){
                min = arr[k] - left2;
            }
            if (arr[k] - right1 < min){
                min = arr[k] - right1;
            }
            if (arr[k] - right2 < min){
                min = arr[k] - right2;
            }
            sum += min;
        }

        cout << "#" << i << " " << sum << endl;
    }
    return 0;
}