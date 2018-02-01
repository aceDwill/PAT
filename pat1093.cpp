/*
    ˼·��1.�������룬��¼ÿ����ĸ���'P'���ָ���
          2.����������룬��¼'T'��������������'A'ʱ����'P'������'T'�����˻�
          3.����������'A'������ۼ���������Ϊ����


*/


#include<iostream>
#include<string>
using namespace std;


int main() {
	
	int leftnumP[100010] = { 0 };
	int mod = 1000000007;
	string str;
	cin >> str;
	int len = str.length();
	for (int i = 0; i < len; i++) {
		if (i > 0) {
			leftnumP[i] = leftnumP[i - 1];
		}
		if (str[i] == 'P') {
			leftnumP[i] ++;
		}
	}
	int rightnumT = 0;
	int numPAT = 0;
	for (int i = len - 1; i >= 0; i--) {
		if (str[i] == 'T') {
			rightnumT++;
		}
		else if (str[i] == 'A'){
			numPAT = (numPAT + leftnumP[i] * rightnumT ) % mod;
		}
	}

	cout << numPAT;
	return 0;
}