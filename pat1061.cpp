#include<iostream>
#include<string>
using namespace std;

int main() {

	string week[] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	int len1 = s1.length();
	int len2 = s3.length();
	bool isWeek = true;	// 标志找到了星期几
	for (int i = 0; i < len1; i++) {
		if (s1[i] == s2[i] && s1[i] >= 'A'&&s2[i] <= 'G'&&isWeek == true) {
			cout << week[s1[i] - 'A'] << ' ';
			isWeek = false;
			continue;
		}
		if (s1[i] == s2[i] && isWeek == false) {
			if (s1[i] >= 'A'&&s1[i] <= 'N') {
				cout << (10 + s1[i] - 'A');
				break;
			}
			if (s1[i] >= '0'&&s1[i] <= '9') {
				cout << '0' << s1[i];
				break;
			}
		}
	}

	for (int i = 0; i < len2; i++) {
		if (s3[i] == s4[i] ) {
			if (s3[i] >= 'A'&&s3[i] <= 'Z' || s3[i] >= 'a'&&s3[i] <= 'z') {
				if (i < 10) {
					cout << ":0" << i;
				}
				else {
					cout << ':' << i;
				}
				break;
			}
		}
	}

	return 0;
}