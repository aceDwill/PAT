/*
	˼·�����������飬һ������洢��ʼ������һ���洢ϴ��һ�κ������Ȼ�����

*/


#include<iostream>
#include<string>
using namespace std;

int main() {

	int K;
	int order[55];  
	cin >> K;

	for (int i = 1; i < 55; i++) {
		cin >> order[i];
	}

	int cards[55];	// ��ʼ����
	int cards_result[55];		// �������
	string cards_color[] = { "S","H","C","D","J" };	//�ƵĻ�ɫ

	for (int i = 1; i < 55; i++) {
		cards[i] = i;
	}

	for (int i = 0; i < K; i++) {
		for (int j = 1; j < 55; j++) {
			cards_result[order[j]] = cards[j];
		}

		for (int k = 1; k < 55; k++) {
			cards[k] = cards_result[k];
		}
	}

	for (int i = 1; i < 55; i++) {
		int curr_num = cards_result[i] - 1;
		cout << cards_color[curr_num / 13] << (curr_num % 13 + 1);
		if (i != 54) {
			cout << " ";
		}
	}

	return 0;
}