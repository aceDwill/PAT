#include<iostream>
#include<algorithm>
using namespace std;

int main() {

	int n;
	cin >> n;
	int num[4] = { 0 };
	for (int i = 0; i < 4; i++) {
		num[i] = n % 10;
		n /= 10;
	}
	sort(num, num + 4);

	int result = -1;
	while (result != 0 && result != 6174) {
		int a = 0, b = 0;	// result = a - b
		for (int i = 0; i < 4; i++) {
			b = b * 10 + num[i];
		}
		for (int i = 3; i >= 0; i--) {
			a = a * 10 + num[i];
		}
		result = a - b;
		printf("%04d - %04d = %04d\n", a, b, result);
		int temp = result;
		// update num[]
		for (int i = 0; i < 4; i++) {
			num[i] = temp % 10;
			temp /= 10;
		}
		sort(num, num + 4);
	}
	return 0;
}