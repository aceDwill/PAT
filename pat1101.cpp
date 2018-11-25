#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {

	int n;
	cin >> n;
	int nums[100010];
	int nums_sorted[100010];
	vector<int> v;
	for (int  i = 0; i < n; i++) {
		cin >> nums[i];
		nums_sorted[i] = nums[i];
	}

	sort(nums_sorted, nums_sorted + n);
	int max_num = 0;
	for (int i = 0; i < n; i++) {
		if (nums_sorted[i] == nums[i] && nums[i] > max_num) {
			v.push_back(nums[i]);
		}
		if (nums[i] > max_num) {
			max_num = nums[i];
		}
	}

	cout << v.size() << endl;
	if (v.size() != 0) {
		cout << v[0];
		for (int i = 1; i < v.size(); i++) {
			cout << " " << v[i];
		}
	} else {
		cout << endl;
	}

	return 0;
}