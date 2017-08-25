/*
	测试点2未通过
	思路：1.先比较两个字符串，找出公共部分，若没有，则输出nai
		  2.在以后每个字符串中找公共字符串，若每个都有则输出公共字符串
		  3.若有一个不包含公共字符串，则输出nai
*/

#include<iostream>
#include<string>
using namespace std;

int main() {

	int N;
	cin >> N;
	cin.get();	//	清除换行符,否则会存在s1中，s1会为空
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	int common_cnt = 0;
	int len1 = s1.length();
	int len2 = s2.length();
	for (int i = 0; i < len1; i++) {
		if (s1[len1 - i - 1] != s2[len2 - i - 1]) {
			break;
		}
		common_cnt++;
	}
	if (common_cnt == 0) {
		cout << "nai";
	}
	else {
		string common_string = s1.substr(len1 - common_cnt);
		bool flag = true;
		for (int i = 2; i < N; i++) {
			string s;
			getline(cin, s);
			if (s.find(common_string) == string::npos) {
				cout << "nai";
				flag = false;
				break;
			}
		}
		if (flag == true) {
			cout << common_string;
		}
	}
	return 0;
}