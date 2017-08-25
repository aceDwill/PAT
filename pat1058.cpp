#include<iostream>
using namespace std;

int main() {

	int g1, s1, k1, g2, s2, k2, g3, s3, k3;
	scanf("%d.%d.%d %d.%d.%d", &g1, &s1, &k1, &g2, &s2, &k2);
	k3 = k1 + k2;
	s3 = s1 + s2;
	g3 = g1 + g2;
	if (k3 >= 29) {
		s3 += 1;
		k3 -= 29;
	}
	if (s3 >= 17) {
		g3 += 1;
		s3 -= 17;
	}
	cout << g3 << '.' << s3 << '.' << k3;

	return 0;

}