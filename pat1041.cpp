/*
	思路：1.遍历出现过数字，用一个数组记录数字出现过的次数
          2.第二次遍历数字，当出现次数为1时输出，没有输出None
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