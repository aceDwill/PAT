#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool comp(string s1, string s2) {
	return s1 + s2 < s2 + s1;
}

int main() {

	int n;
	cin >> n;
	string segments[10010];

	for (int i = 0; i < n; i++) {
		cin >> segments[i];
	}

	sort(segments, segments + n, comp);

	string result = "";
	// erase 0 in front of the first number
	if (segments[0][0] == '0') {
		result = segments[0].substr(1);
	}

	for (int i = 1; i < n; i++) {
		result += segments[i];
	}

	if (result.length() == 0) {
		cout << 0;
	}
	else {
		cout << result;
	}

}