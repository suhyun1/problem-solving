#include <iostream>
using namespace std;

int getScore(int a, int b) {

	if (a == b) {
		return a + 100;
	} else {
		return (a + b) % 10;
	}

}

int main() {

	int a, b;		// 영악한 영학이의 두 카드.

	int i, j;		// 불쌍한 상대편의 두 카드.

	int cards[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

 	cin >> a >> b;

	for (i = 0; i < 20; i++) {
		if (cards[i] == a) {
			cards[i] = cards[19];		// a가 있는 칸에 10을 줘버림.
			break;
		}
	}

	for (i = 0; i < 19; i++) {
		if (cards[i] == b) {
			cards[i] = cards[18];		// b가 있는 칸에 9를 줘버림.
			break;
		}
	}

	int count = 0;
	for (i = 0; i < 18; i++) {
		for (j = 0; j < 18; j++) {

			if (i == j) {
				continue;
			}

			if (getScore(a, b) > getScore(cards[i], cards[j])) {
				count++;
			}

		}
	}

	cout << fixed;
	cout.precision(3);

	cout << (double)count / 306.0;

}
