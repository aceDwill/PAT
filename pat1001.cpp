/*
	思路：1.获取a+b结果的位数
		  2.将结果分成前面不足或等于三位部分和剩余部分
		  3.输出前面部分和','后面部分每三位打印一个','
*/

#include<iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b;
	c = a + b;
	//  c为负数时先输出负号
	if (c < 0) {
		c = -c;
		cout << '-';
	}
	int temp = c;
	int record = 1; // 记录和c等长位数的如1，10，100，1000，...
	int len_c = 0; // 记录c的位数
	// 处理结果为0的情况
	if (c == 0) {
		cout << 0;
		return 0;
	}
	while (temp > 0) {
		temp /= 10;
		record *= 10;
		len_c++;
	}
	record /= 10;          //  使record与c的位数相等
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

