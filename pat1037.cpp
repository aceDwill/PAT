#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {

	int nc, np;
	// collection of positive coupons, negative coupons, 
	// positive products and negative products
	vector<int> c_p, c_n, p_p, p_n;
	cin >> nc;
	int value;
	for (int i = 0; i < nc; i++) {
		cin >> value;
		if (value > 0) {
			c_p.push_back(value);
		}
		else if (value < 0) {
			c_n.push_back(value);
		}
	}
	cin >> np;
	for (int i = 0; i < np; i++) {
		cin >> value;
		if (value > 0) {
			p_p.push_back(value);
		}
		else if (value < 0) {
			p_n.push_back(value);
		}
	}
	
	sort(c_p.begin(), c_p.end());
	sort(c_n.begin(), c_n.end());
	sort(p_p.begin(), p_p.end());
	sort(p_n.begin(), p_n.end());

	// positive number in decreasing order
	reverse(c_p.begin(), c_p.end());
	reverse(p_p.begin(), p_p.end());

	int len1 = min(c_p.size(), p_p.size());
	int len2 = min(c_n.size(), p_n.size());

	int max_money = 0;
	for (int i = 0; i < len1; i++) {
		max_money += c_p[i] * p_p[i];
	}

	for (int i = 0; i < len2; i++) {
		max_money += c_n[i] * p_n[i];
	}

	cout << max_money;
	return 0;
}