/*
	    思路：按月饼单价从高到低依次卖月饼，数量不够市场数量的卖下一种，直到满足市场数量


*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct mooncake{

	double amount;
	double price;
	double unit_price;
};

bool comp(mooncake m1, mooncake m2) {
	return m1.unit_price > m2.unit_price;
}

int main() {

	int N;
	double D;
	cin >> N >> D;
	vector<mooncake> mooncakes;
	mooncake m;
	for (int i = 0; i < N; i++) {
		cin >> m.amount;
		mooncakes.push_back(m);
	}
	for (int i = 0; i < N; i++) {
		cin >> mooncakes[i].price;
		mooncakes[i].unit_price = mooncakes[i].price / mooncakes[i].amount;
	}
	sort(mooncakes.begin(), mooncakes.end(), comp);

	double profit = 0;
	for (int i = 0; i < N; i++) {
		if (mooncakes[i].amount < D) {
			profit += mooncakes[i].price;
			D -= mooncakes[i].amount;
		}
		else {
			profit += D * mooncakes[i].unit_price;
			break;
		}
	}

	printf("%.2f", profit);
	return 0;
}