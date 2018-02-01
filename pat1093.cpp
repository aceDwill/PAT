/*
    思路：1.遍历输入，记录每个字母左边'P'出现个数
          2.倒序遍历输入，记录'T'个数，并在遇到'A'时计算'P'个数与'T'个数乘积
          3.将遇到所有'A'的情况累加起来，即为所求


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