/*
	˼·��1.��ȡa+b�����λ��
		  2.������ֳ�ǰ�治��������λ���ֺ�ʣ�ಿ��
		  3.���ǰ�沿�ֺ�','���沿��ÿ��λ��ӡһ��','
*/

#include<iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b;
	c = a + b;
	//  cΪ����ʱ���������
	if (c < 0) {
		c = -c;
		cout << '-';
	}
	int temp = c;
	int record = 1; // ��¼��c�ȳ�λ������1��10��100��1000��...
	int len_c = 0; // ��¼c��λ��
	// ������Ϊ0�����
	if (c == 0) {
		cout << 0;
		return 0;
	}
	while (temp > 0) {
		temp /= 10;
		record *= 10;
		len_c++;
	}
	record /= 10;          //  ʹrecord��c��λ�����
	int leftnum = len_c % 3;
	if (leftnum == 0) {
		leftnum = 3;
	}
	for (int i = 0; i < leftnum; i++) {
		cout << c / record;
		c %= record;
		record /= 10;
	}

	if (len_c - leftnum != 0) {
		cout << ',';
	}
	for (int i = 1; i <= len_c - leftnum; i++) {
		if (i % 4 == 0 && i != len_c - leftnum) {
			cout << ',';
		}
		cout << c / record;
		c %= record;
		record /= 10;
	}

	return 0;
}

