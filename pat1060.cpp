/*
	˼·��1.ȥ���ַ���û�õ�0
		  2.��ȡ��һ��������Ĳ��֣�����Ч���ֲ���
		  3.ͬʱ��ȡָ������
		  4.�Ƚ���Ч���ֺ�ָ�������Ƿ����

*/

#include<iostream>
#include<string>
using namespace std;

int N;

string deal(string s, int &e) {

	int k = 0;	//	��¼С��������
	//	ɾ��ǰ����Ч��0����00001�������
	while (s[0] == '0') {
		s.erase(s.begin());
	}
	//	С��1�����
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

		//	����1ʱ����С�����û��С���㴦��
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