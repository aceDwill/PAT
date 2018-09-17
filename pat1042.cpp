/*
	思路：用两个数组，一个数组存储初始牌序，另一个存储洗牌一次后的牌序，然后迭代

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

	int cards[55];	// 初始牌序
	int cards_result[55];		// 最后牌序
	string cards_color[] = { "S","H","C","D","J" };	//牌的花色

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