/*
	���Ե�2δͨ��
	˼·��1.�ȱȽ������ַ������ҳ��������֣���û�У������nai
		  2.���Ժ�ÿ���ַ������ҹ����ַ�������ÿ����������������ַ���
		  3.����һ�������������ַ����������nai
*/

#include<iostream>
#include<string>
using namespace std;

int main() {

	int N;
	cin >> N;
	cin.get();	//	������з�,��������s1�У�s1��Ϊ��
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