/*
	˼·:���������洢���ݣ��±��ʾ������ֵ��ʾϵ����
		 ���ֵ��Ϊ0����
*/

#include<iostream>
using namespace std;

int main() {
	float a[1001] = { 0 };
	int k1, k2;
	cin >> k1;
	for (int i = 0; i < k1; i++) {
		int n;
		float an;
		cin >> n >> an;
		a[n] += an;
	}
	cin >> k2;
	for (int i = 0; i < k2; i++) {
		int n;
		float an;
		cin >> n >> an;
		a[n] += an;
	}
	int cnt = 0;
	for (int i = 0; i < 1001; i++) {
		if (a[i] != 0) {
			cnt++;
		}
	}
	cout << cnt;
	for (int i = 1000; i >= 0; i--) {
		if (a[i] != 0) {
			printf(" %d %.1f", i, a[i]);
		}
	}
	return 0;
}