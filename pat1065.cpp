/* 
	1.要考虑到溢出的情况
	2.a+b不能直接和c比较，要保存到long long变量中，不然后面两组数据会报错
*/
#include<iostream>
using namespace std;

int main() {

	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		bool flag = false;
		long long a, b, c, sum;
		//scanf("%lld%lld%lld", &a, &b, &c);
		cin >> a >> b >> c;
		sum = a + b;
		if (a > 0 && b > 0 && sum < 0) {
			flag = true;
		}
		else if (a < 0 && b < 0 && sum >= 0) {
			flag = false;
		}
		else if (a+b > c) {
			flag = true;
		}
		cout << "Case #" << i << ": ";
		if (flag) {
			cout << "true" << endl;
		}
		else {
			cout << "false" << endl;
		}
	}
	return 0;
}