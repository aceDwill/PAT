#include<iostream>
#include<algorithm>
using namespace std;

int main() {

	int n;
	long long p;
	cin >> n >> p;
	int seq[100010];
	for (int i = 0; i < n; i++) {
		cin >> seq[i];
	}

	sort(seq, seq + n);

	int max_num = 0, temp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + max_num; j < n; j++) {
			if (seq[j] <= seq[i] * p) {
				temp = j - i + 1;
				max_num = max(temp, max_num);
			} else {
				break;
			}
		}

	}

	cout << max_num << endl;


	return 0;
}