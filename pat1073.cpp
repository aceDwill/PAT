#include<iostream>
#include<string>
using namespace std;

int main() {

	string s;
	cin >> s;
	int len = s.length();
	if (s[0] == '-') {
		cout << '-';
	}
	int index_E = 0;
	//找到'E'的位置
	for (int i = 0; i < len; i++){
		if (s[i] == 'E') {
			index_E = i;
		}
	}
	string exes = "";
	for (int i = index_E + 1; i < len; i++) {
		exes += s[i];
	}
	int exei = stoi(exes);	//	将字符串形式的幂值转化为int形式
	if (exei < 0) {
		cout << "0.";
		for (int i = 0; i < -exei - 1; i++) {
			cout << '0';
		}
		cout << s[1];
		cout << s.substr(3, index_E - 3);
	}
	else {
		if (exei >= index_E - 3) {
			cout << s[1] << s.substr(3, index_E - 3);
			for (int i = 0; i < exei - index_E + 3; i++) {
				cout << '0';
			}
		}
		else {
			cout << s[1] << s.substr(3, exei) << '.' 
				<< s.substr(3 + exei, index_E - 3 - exei);
		}
	}
	return 0;
}