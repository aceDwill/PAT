/*
	˼·��1.�ȱ����̵�ӵ�е�beads����һ����������¼���ֹ�������
          2.����Eva��Ҫ��beads������̵�û�л�����������ȱ����+1
          3.���ȱ����Ϊ0�����Yes���������No
	
*/

#include<iostream>
#include<string>
using namespace std;

int main() {

	string shop_beads, Eva_beads;
	cin >> shop_beads >> Eva_beads;
	int shop_beads_num[130] = { 0 };		// ��¼�̵���ֹ���beads��������ʼ��Ϊ0
	for (int i = 0; i < shop_beads.length(); i++) {
		shop_beads_num[shop_beads[i]] += 1;
	}
	int beads_missing = 0;	// Eva��Ҫ���̵�û��beads������ʼ��Ϊ0
	for (int i = 0; i < Eva_beads.length(); i++) {
		shop_beads_num[Eva_beads[i]] -= 1;
		if (shop_beads_num[Eva_beads[i]] < 0) {
			beads_missing += 1;
		}
	}

	if (beads_missing == 0) {
		cout << "Yes " << shop_beads.length() - Eva_beads.length();
	}
	else {
		cout << "No " << beads_missing;
	}

	return 0;
}