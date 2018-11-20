/*
	Solution:  1.use book[] to convert char to number
			  2.convert the chosen number to decimal ,assign it temp
			  3.assign (the max number of all digits) + 1 to left,
				assign max(temp,left)+1 to right,
			  4.use binary search to find the radix
	attention:  1.the max radix is not 36, radix >= 2
			   2.input: 9 9 1 7 ,this test case should output "Impossible",
				 not 10
			   3.Integer may be overflow,use long

*/


#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int book[200]; // convert char to decimal

long long convert10(string s, long long radix) {
	long long result = 0;
	int index = 0;
	for (int i = 0; i < s.length(); i++) {
		// if num of the digit > radix, can't convert to deciaml
		if (book[s[i]] >= radix) {
			return -1;
		} else {
			result = result * radix + book[s[i]];
		}
	}

	return result;
}

// find the max num of all digits
int find_max_num(string s) {
	int max_num = -1;
	for (int i = 0; i < s.length(); i++) {
		if (book[s[i]] > max_num) {
			max_num = book[s[i]];
		}
	}
	return max_num;
}

long long binary_search(long long left, long long right, long long n1, string n2) {

	while (left <= right) {
		long long mid = (left + right) / 2;
		long long temp = convert10(n2, mid);
		// temp may overflow
		if (temp < 0 || temp > n1) {
			right = mid - 1;
		} else if (temp < n1) {
			left = mid + 1;
		} else if (temp == n1) {
			return mid;
		}

	}
	// can't find the radix
	return -1;
}

int main() {

	for (char i = '0'; i <= '9'; i++) {
		book[i] = i - '0';
	}

	for (char i = 'a'; i <= 'z'; i++) {
		book[i] = i - 'a' + 10;
	}

	string n1, n2;
	int tag, radix;	
	cin >> n1 >> n2 >> tag >> radix;
	long long temp;
	string n;	// the num to be addressed
	if (tag == 1) {
		temp = convert10(n1, radix);
		n = n2;
	} else {
		temp = convert10(n2, radix);
		n = n1;
	}
	if (temp == -1) {
		cout << "Impossible";
		return 0;
	}

	long long left = find_max_num(n) + 1;
	long long right = max(left, temp) + 1;
	long long result = binary_search(left, right, temp, n);
	if (result == -1) {
		cout << "Impossible";
	} else {
		cout << result;
	}




	return 0;
}