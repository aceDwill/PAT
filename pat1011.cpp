#include<iostream>
using namespace std;

int main() {
	float max_odds = 0, result = 1;
	for (int i = 0; i < 3; i++) {
		float w, t, l;
		cin >> w >> t >> l;
		if (w > t) {
			cout << 'W' << ' ';
			max_odds = w;
		}
		else if (t < l) {
			cout << 'L' << ' ';
			max_odds = l;
		}
		else {
			cout << 'T' << ' ';
			max_odds = t;
		}
		result *= max_odds;
	}
	result = (result*0.65 - 1) * 2;
	printf("%.2f", result);

	return 0;

}