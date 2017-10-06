/*
	思路：1.去掉字符串没用的0
		  2.获取第一个数非零的部分，即有效数字部分
		  3.同时获取指数部分
		  4.比较有效数字和指数部分是否相等

*/

#include<iostream>
#include<string>
using namespace std;

int N;

string deal(string s, int &e) {

	int k = 0;	//	记录小数点索引
	//	删除前面无效的0，如00001这种情况
	while (s[0] == '0') {
		s.erase(s.begin());
	}
	//	小于1的情况
	if (s[0] == '.') {
		s.erase(s.begin());
		while (s[0] == '0') {
			s.erase(s.begin());
			--e;
		}
	}
	else {
		while (k < s.length() && s[k] != '.') {
			++k;
		}

		//	大于1时分有小数点和没有小数点处理
		if (k < s.length()) {
			s.erase(s.begin() + k);
			e = k;
		}
		else {
			e = s.length();
		}
	}
	if (s.length() == 0) {
		e = 0;
	}
	string result = "";
	if (N < s.length()) {
		for (int i = 0; i < N; i++) {
			result += s[i];
		}
	}
	else {
		result += s;
		for (int i = 0; i < N - s.length(); i++) {
			result += '0';
		}
	}

	return result;

}

int main() {

	cin >> N;
	string A, B;
	cin >> A >> B;
	int e1 = 0;
	int e2 = 0;
	A = deal(A, e1);
	B = deal(B, e2);
	if (A == B && e1 == e2) {
		cout << "YES 0." << A << "*10^" << e1;
	}
	else {
		cout << "NO 0." << A << "*10^" << e1 << " 0." << B << "*10^" << e2;
	}

}