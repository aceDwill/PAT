#include<iostream>
#include<string>
using namespace std;

string dic = "0123456789ABC";
string to13(int x) {
	char result[3] = {'0','0','\0'};	//	加'\0'避免char[]转化为字符串时没有终止符而导致的乱码
	int i = 1;	
	while (x > 0) {
		result[i] = dic[x % 13];
		x /= 13;
		i--;
	}
	string sresult(result);
	return(sresult);
}

int main() {

	
	int r, g, b;
	cin >> r >> g >> b;
	cout << '#' << to13(r) << to13(g) << to13(b);
	return 0;
}