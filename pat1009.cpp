/*
	思路：和pat1002思路一致，用数组的下标表示项数，数组的值表示系数
*/


#include<iostream>
using namespace std;

int main() {

	float poly1[1001] = { 0 };
	float poly2[2001] = { 0 };
	int k1;
	cin >> k1;
	for (int i = 0; i < k1; i++) {
		int n;
		float an;
		cin >> n >> an;
		poly1[n] += an;
		
	}
	int k2;
	cin >> k2;
	for (int i = 0; i < k2; i++) {
		int n;
		float an;
		cin >> n >> an;
		for (int j = 0; j < 1001; j++) {
			poly2[n + j] += an * poly1[j];
		}
	}
	int cnt = 0;
	for (int i = 0; i < 2001; i++) {
		if (poly2[i] != 0) {
			cnt++;
		}
	}
	cout << cnt;
	for (int i = 2000; i >= 0; i--) {
		if (poly2[i] != 0) {
			printf(" %d %.1f", i, poly2[i]);
		}
	}
	return 0;
}