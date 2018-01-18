/*
	˼·��1.�Ȱ��������д�С�������򣬿��Եõ���������
          2.������ȫ���������ص㣬����������ڵ�ĸ������Ӷ����Եõ����ڵ��λ��
          3.������еݹ���ã����Եõ������������

*/

#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<int> origin, level_order_list;
void level_order(int inl, int inr, int postion) {
	if (inr < inl) return;
	if (inl == inr) {
		level_order_list[postion] = origin[inl];	//	ֻ��һ���ڵ�����
		return;
	}
	int num = inr - inl + 1;		//	�ڵ����
	int depth = log2(num) + 1;		//	��ȫ�������߶�
	int last_depth_nodes = num - pow(2, depth - 1) + 1;	//	���һ��ڵ����
	int left_num_nodes;		//	�������ڵ����
	if (last_depth_nodes <= pow(2, depth - 2)) {
		left_num_nodes = num - pow(2, depth - 2);
	}
	else {
		left_num_nodes = pow(2, depth - 1) - 1;
	}
	int root = inl + left_num_nodes;		//	���ڵ������
	level_order_list[postion] = origin[root];
	level_order(inl, root - 1, 2 * postion + 1);
	level_order(root + 1, inr, 2 * postion + 2);
}

int main() {

	
	scanf("%d", &N);
	origin.resize(N);
	level_order_list.resize(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &origin[i]);
	}
	sort(origin.begin(), origin.end());
	
	level_order(0, N - 1, 0);
	printf("%d", level_order_list[0]);
	for (int i = 1; i < N; i++) {
		printf(" %d", level_order_list[i]);
	}
	return 0;
}