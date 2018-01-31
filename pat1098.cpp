/*
   思路：在插入排序过程中和part_sort列表比较，如果存在相等的情况则是插入排序，否则是堆排序
*/


#include<iostream>
#include<algorithm>
using namespace std;

int N;
int origin[110], temp_origin[110];
int part_sort[110];
//	判断两个数组是否相等
bool isSame(int a[], int b[]) {
	for (int i = 0; i < N; i++) {
		if (a[i] != b[i]) {
			return false;

		}
	}
	return true;
}

void print(int a[]) {
	printf("%d", a[0]);
	for (int i = 1; i < N; i++) {
		printf(" %d", a[i]);
	}
}



//	大根堆向下调整
void downAdjust(int low, int high) {
	int i = low;
	int j = 2 * i + 1;
	while (j <= high) {
		if (j + 1 <= high && origin[j + 1] > origin[j]) {
			j = j + 1;
		}
		if (origin[i] < origin[j]) {
			swap(origin[i], origin[j]);
			i = j;
			j = 2 * i + 1;
		}
		else {
			break;
		}

	}
}

void heapSort() {
	bool flag = false;
	for (int i = N / 2 - 1; i >= 0; i--) {
		downAdjust(i, N - 1);
	}
	for (int i = N - 1; i >= 0; i--) {
		if (isSame(origin, part_sort)) {
			flag = true;
		}
		swap(origin[0], origin[i]);
		downAdjust(0, i - 1);
		if (flag) {
			printf("Heap Sort\n");
			print(origin);
			return;

		}
	}

}


int main() {

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &origin[i]);
		temp_origin[i] = origin[i];
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &part_sort[i]);
	}

	bool isInsertsort = false;
	for (int i = 1; i < N; i++) {
		sort(temp_origin, temp_origin + i);
		if (i!=1 && isSame(temp_origin, part_sort)) {
			sort(temp_origin, temp_origin + i + 1);
			printf("Insertion Sort\n");
			print(temp_origin);
			isInsertsort = true;
			break;
		}
	}

	if (!isInsertsort) {
		heapSort();
	}

	return 0;
}