/*
	˼·��1.�������ֹ����֣���һ�������¼���ֳ��ֹ��Ĵ���
          2.�ڶ��α������֣������ִ���Ϊ1ʱ�����û�����None
*/


#include<iostream>
#include<vector>
using namespace std;

int main() {

	int N;
	int appeared_count[10010] = { 0 };
	cin >> N;
	int bet_num;
	vector<int> v;
	bool has_printed = false;
	for (int i = 0; i < N; i++) {
		cin >> bet_num;
		appeared_count[bet_num]++;
		v.push_back(bet_num);
	}
	for (int i = 0; i < N; i++) {
		if (appeared_count[v[i]] == 1) {
			cout << v[i];
			has_printed = true;
			break;
		}
	}

	if (!has_printed) {
		cout << "None";
	}
	return 0;

}