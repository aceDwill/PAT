/*
	solution: 1.use int[] sum_of_1toj to save sum of diamond 1 to j;
	          2.if sum_of_1toj[right] - sum_of_1toj[left] == m ,add string "left-right" to solution
	          3.if sum_of_1toj[right] - sum_of_1toj[left] < m, left ++
	          4.if sum_of_1toj[right] - sum_of_1toj[left] > m, right ++
	attention: cin cause time limit exceed
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {

	int n, m;
	int diamonds[100010];
	int sum_of_1toj[100010];		// sum of Diamond 1 to Diamond j
	sum_of_1toj[0] = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &diamonds[i]);
		sum_of_1toj[i] = sum_of_1toj[i - 1] + diamonds[i];
	}
	int left = 0;
	int right = 1;
	// find the first sum >= m
	while (sum_of_1toj[right] < m) {
		right++;
	}

	bool has_solution = false;	// has solution which Di + ... + Dj = M
	int min_sum = 200000000;
	vector<string> solutions;

	while (right <= n) {
		int temp_sum = sum_of_1toj[right] - sum_of_1toj[left];
		string temp_solution = to_string(left + 1) + "-" + to_string(right);

		if (temp_sum == m) {
			if (has_solution) {
				solutions.push_back(temp_solution);
			} else {
				solutions.clear();	// clear the solution which Di + ... + Dj != M
				solutions.push_back(temp_solution);
				has_solution = true;
			}
			left++;
			right++;
		} else if (temp_sum < m) {
			right++;
		} else {
			left++;
			if (!has_solution) {
				if (temp_sum < min_sum) {
					min_sum = temp_sum;
					solutions.clear();
					solutions.push_back(temp_solution);
				} else if (temp_sum == min_sum) {
					solutions.push_back(temp_solution);
				}
			}
		}
	}
	for (int i = 0; i < solutions.size(); i++) {
		cout << solutions[i] << endl;
	}

}