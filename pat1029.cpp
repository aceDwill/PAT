#include<iostream>
using namespace std;

int main() {


	int n1, n2;
	scanf("%d", &n1);
	int s1[200010];
	for (int i = 0; i < n1; i++) {
		scanf("%d", &s1[i]);
	}
	s1[n1] = (1 << 31) - 1;
	scanf("%d", &n2);
	int median = (n1 + n2 - 1) / 2;
	int i = 0, j = 0, count = 0;
	int temp;
	for (j = 0; j < n2; j++) {
		scanf("%d", &temp);
		while (s1[i] < temp) {
			if (count == median) {
				cout << s1[i];
			}
			count++;
			i++;
		}
		
		if (count == median) {
			cout << temp;
		}
		count++;
	}
	while (i<n1) {
		if (count == median) {
			cout << s1[i];
		}
		count++;
		i++;
	}

	return 0;
}