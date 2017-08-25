/*
	思路：遍历找出满足n1 = n3 = max { k| k <= n2 for all 3 <= n2 <= N } 
		  with n1 + n2 + n3 - 2 = N.

h   !
e   d	 注意：vertical_count 为h,e,l这部分，n1,n3为h,e,l,l这部分    
l   l
lowor

*/

#include<iostream>
#include<string>
using namespace std;

int main() {

	string s;
	cin >> s;
	int len = s.length();
	int vertical_count = 0;
	for (int i = 1; i <= len; i++) {
		int n3 = len - 2 * i;
		if (i == n3) {
			vertical_count = i - 1;
			break;
		}
		else if (i + 1 > n3) {
			vertical_count = i - 1;
			break;
		}
	}
	int blank_count = len - 2 * vertical_count - 2;
	for (int i = 0; i < vertical_count; i++) {
		cout << s[i];

		for (int j = 0; j < blank_count; j++) {
			cout << " ";
		}
		cout << s[len - i - 1] << endl;
	}
	for (int i = 0; i < blank_count + 2; i++) {
		cout << s[i + vertical_count];
	}
	return 0;
}