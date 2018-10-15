/*
		solution: 1.create an array to save the index of number
		          2.if 0 is not at the index of 0,swap 0 and the number whose value equals the
		            index of 0
		          3.if 0 is at the index of 0,find out the first number not at the right index,
		            swap them

*/

#include<iostream>
using namespace std;

int main() {

	int seq[100010];
	int index_of_num[100010];		// save the indexes of numbers 
	int n;
	cin >> n;
	int left_num = n - 1;		// the number of numbers not at the right index except 0
	int num_swaps = 0;		// the number of swaps

	for (int i = 0; i < n; i++) {
		cin >> seq[i];
		index_of_num[seq[i]] = i;

		if (seq[i] == i && i != 0) {
			left_num--;
		}
	}

	int index_0, index_swap;
	int k = 1;		// the first number not at the right index
	while (left_num > 0) {
		index_0 = index_of_num[0];
		if (index_0 != 0) {
			index_swap = index_of_num[index_0];
			left_num--;
			index_of_num[0] = index_swap;
		}
		else {
			while (k < n) {
				if (seq[k] != k) {
					index_swap = k;
					index_of_num[0] = k;
					index_of_num[seq[k]] = 0;
					break;
				}
				k++;
			}

		}

		swap(seq[index_0], seq[index_swap]);
		num_swaps++;
	}

	cout << num_swaps;

	return 0;
}