/*
	思路：1.先遍历打印字符串，用一个map存储出现过的字符的大写形式
	      2.遍历原字符串，将map中没出现过字符输出，并加入map中

*/

#include<iostream>
#include<string>
#include<map>
#include<cctype>
using namespace std;

int main() {

	string original, typed_out;
	cin >> original >> typed_out;
	map<char, int> book;
	for (int i = 0; i < typed_out.length(); i++) {
		char current_c = toupper(typed_out[i]);	// 转化为大写形式
		book[current_c] = 1;
	}
	for (int i = 0; i < original.length(); i++) {
		char current_c = toupper(original[i]);		// 转化为大写形式
		// map值为0表示没出现过，输出并将其值改为1，表示出现过
		if (book[current_c] == 0) {
			cout << current_c;
			book[current_c] = 1;
		}
	}
	
	return 0;
}