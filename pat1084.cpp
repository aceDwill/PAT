/*
	˼·��1.�ȱ�����ӡ�ַ�������һ��map�洢���ֹ����ַ��Ĵ�д��ʽ
	      2.����ԭ�ַ�������map��û���ֹ��ַ������������map��

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
		char current_c = toupper(typed_out[i]);	// ת��Ϊ��д��ʽ
		book[current_c] = 1;
	}
	for (int i = 0; i < original.length(); i++) {
		char current_c = toupper(original[i]);		// ת��Ϊ��д��ʽ
		// mapֵΪ0��ʾû���ֹ������������ֵ��Ϊ1����ʾ���ֹ�
		if (book[current_c] == 0) {
			cout << current_c;
			book[current_c] = 1;
		}
	}
	
	return 0;
}