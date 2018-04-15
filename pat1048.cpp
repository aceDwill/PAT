#include<iostream>
#include<algorithm>
using namespace std;

int coins[100010], coin_count[1000];	// 记录输入值，以及出现硬币的次数
int main() {

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> coins[i];
		coin_count[coins[i]] += 1;
	}

	sort(coins, coins + N);
	bool has_solution = false;
	for (int i = 0; i < N; i++) {
		int num = M - coins[i];
		if (num == coins[i] && coin_count[num] == 1) {
			continue;
		}
		if (coin_count[num] >= 1) {
			cout << coins[i] << " " << num;
			has_solution = true;
			break;
		}
	}

	if (!has_solution) {
		cout << "No Solution";
	}


	return 0;
}