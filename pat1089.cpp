/*
	思路：在归并排序过程中判断是否与排过序的序列相等
	      如果存在相等序列则是归并排序，否则为插入排序
*/

#include<iostream>
#include<algorithm>
using namespace std;

int n;
int init_seq[200];
int partially_sorted_seq[200];

bool is_arr_equal(int a[], int b[]) {
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) {
			return false;
		}
	}
	return true;
}

bool merge_sort() {
	bool is_merge_sort = false;
	for (int i = 2; i < 2 * n; i *= 2) {
		if (is_arr_equal(init_seq, partially_sorted_seq) && i != 2) {
			is_merge_sort = true;
		}
		for (int j = 0; j < n; j += i) {
			sort(init_seq + j, init_seq + min(j + i, n));
		}
		if (is_merge_sort) {
			return true;
		}
	}

	return false;
}

void insert_sort() {
	bool has_inserted = false;	// 一段序列有序表示没有插入过数
	for (int i = 1; i < n; i++) {
		int temp = partially_sorted_seq[i];
		int j = i;
		while (j > 0 && temp < partially_sorted_seq[j - 1]) {
			partially_sorted_seq[j] = partially_sorted_seq[j - 1];
			j--;
			has_inserted = true;
		}
		partially_sorted_seq[j] = temp;
		if (has_inserted) {
			break;
		}
	}

}



void print_arr(int a[]) {
	cout << a[0];
	for (int i = 1; i < n; i++) {
		cout << " " << a[i];
	}
}

int main() {


	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> init_seq[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> partially_sorted_seq[i];
	}


	if (merge_sort()) {
		cout << "Merge Sort" << endl;
		print_arr(init_seq);
	} else {
		cout << "Insertion Sort" << endl;
		insert_sort();
		print_arr(partially_sorted_seq);
	}

	return 0;
}