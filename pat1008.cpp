#include<iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int now = 0, sum = 0;
	for (int i = 0; i < N; i++) {
		int floor;
		cin >> floor;
		if (floor >= now) {
			sum += 6 * (floor - now);
		}
		else {
			sum += 4 * (now - floor);
		}
		now = floor;
		sum += 5;
	}
	cout << sum;

	return 0;
}