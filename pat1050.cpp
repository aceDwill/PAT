#include<iostream>
#include<string>
using namespace std;

int main() {

	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	int char_book[130] = { 0 };
	for (int i = 0; i < s2.length(); i++) {
		char_book[s2[i]] += 1;
	}
	for (int i = 0; i < s1.length(); i++) {
		if (char_book[s1[i]] == 0) {
			cout << s1[i];
		}
	}

	return 0;
}