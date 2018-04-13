/*
	思路：1.先遍历商店拥有的beads，用一个数组来记录出现过的数量
          2.遍历Eva需要的beads，如果商店没有或数量不够，缺少数+1
          3.如果缺少数为0，输出Yes，否则输出No
	
*/

#include<iostream>
#include<string>
using namespace std;

int main() {

	string shop_beads, Eva_beads;
	cin >> shop_beads >> Eva_beads;
	int shop_beads_num[130] = { 0 };		// 记录商店出现过的beads数量，初始化为0
	for (int i = 0; i < shop_beads.length(); i++) {
		shop_beads_num[shop_beads[i]] += 1;
	}
	int beads_missing = 0;	// Eva需要但商店没有beads数，初始化为0
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