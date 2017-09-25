/*
	思路：划分为每四位处理

*/


#include<iostream>
#include<string>
using namespace std;

int main() {

	string chinese_num[] = { "ling","yi","er","san","si","wu",
								"liu","qi","ba","jiu" };
	string chinese_bit[] = { "Shi","Bai","Qian","Wan","Yi" };
	string N;
	cin >> N;
	int orign_len = N.length();
	//	处理输入为0的特殊情况
	if (N == "0") {
		cout << "ling";
		return 0;
	}
	if (N[0] == '-') {
		cout << "Fu";
		N = N.substr(1);
	}
	int len = N.length();
	//	得到首尾索引
	int left = 0;
	int right = len - 1;

	//	使left和right处于同一四位数之内
	while (right >= 3){
		right -= 4;
	}

	while (left < len) {
		bool flag = false;	//	表示有累积零
		bool isPrint = false;		//	表示每四位有数输出
		while (left <= right) {
			if (N[left] == '0') {
				flag = true;
			}
			else {
				if (flag == true) {
					cout << " ling";
					flag = false;
				}
				if (left == 0 && len == orign_len) {
					cout << chinese_num[N[left] - '0'];
				}
				else{
					cout << " " << chinese_num[N[left] - '0'];
					
				}
				if (right - left > 0) {
					cout << " " << chinese_bit[right - left - 1];
				}
				isPrint = true;
			}
			left++;
		}
		if (isPrint && left != len) {
			cout << " " << chinese_bit[(len - right) / 4 + 2];
		}
		right += 4;
	}

	return 0;
}