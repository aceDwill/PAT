#include<iostream>
#include<string>
using namespace std;
int main() {
	string s;
	cin >> s;
	int sum = 0;
	for (int i = 0; i < s.length(); i++) {
		sum += s[i] - '0';
	}
	s = to_string(sum);
	for (int i = 0; i < s.length(); i++) {
		switch (s[i])
		{
		case '0': cout << "zero"; break;
		case '1': cout << "one"; break;
		case '2': cout << "two"; break;
		case '3': cout << "three"; break;
		case '4': cout << "four"; break;
		case '5': cout << "five"; break;
		case '6': cout << "six"; break;
		case '7': cout << "seven"; break;
		case '8': cout << "eight"; break;
		case '9': cout << "nine"; break;
		default:
			break;
		}
		if (i != s.length() - 1){
			cout << ' ';
		}
	}

	return 0;
}