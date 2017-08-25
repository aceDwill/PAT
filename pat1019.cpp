#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N, b;
	vector<int> v;
	cin >> N >> b;
	if (N == 0) {
		v.push_back(0);
	}
	while (N > 0)
	{
		v.push_back(N%b);
		N /= b;
	}
	bool isPalinNum = true;
	int len = v.size();
	for (int i = 0; i < len/2; i++) {
		if (v[i] != v[len - i - 1]) {
			isPalinNum = false;
			break;
		}
	}
	if (isPalinNum) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	for (int i = len - 1; i >= 0; i--) {
		cout << v[i];
		if (i != 0) {
			cout << ' ';
		}
	}
	return 0;

}