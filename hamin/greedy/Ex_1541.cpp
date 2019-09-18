#include <iostream>

char a[100];

int sum() {
	int ret = 0;	// 마지막에 리턴해줄 총합.
	int sym = 1;	// 계산된 숫자에 부호를 붙여주기 위함, 1과 -1만 존재.
	for (int i = 0; a[i]; i++) {
		if (a[i] == '+')
			sym = 1;
		else if (a[i] == '-')
			sym = -1;
		else {
			int num = 0;	// num은 각각의 수.
			while (a[i] >= '0' && a[i] <= '9') {	// +나 -가 나오기 전까지만 숫자를 자릿수 고려 계산.
				num = num * 10 + (a[i] - '0');		// 자릿수 고려 계산.
				i++;
			}
			i--;
			ret += num * sym;	// 부호붙이기.
		}
	}
	return ret;
}

int main() {
	scanf("%s", a);

	int minus = 0;

	for (int i = 0; a[i]; i++) {
		if (a[i] == '-')	// - 부호가 있다면.
			minus = 1;		// - 부호가 1개 있다는!.
		if (minus && a[i] == '+')	// minus가 1 이상이고(앞에 -가 있고), +가 나왔다면.
			a[i] = '-';		// +를 -로 바꿔버리자.
	}

	printf("%d\n", sum());

    return 0;
}
