/*
	思路：1.先把输入序列从小到大排序，可以得到中序序列
          2.根据完全二叉树的特点，求出左子树节点的个数，从而可以得到根节点的位置
          3.对其进行递归调用，可以得到层序遍历序列

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
		level_order_list[postion] = origin[inl];	//	只有一个节点的情况
		return;
	}
	int num = inr - inl + 1;		//	节点个数
	int depth = log2(num) + 1;		//	完全二叉树高度
	int last_depth_nodes = num - pow(2, depth - 1) + 1;	//	最后一层节点个数
	int left_num_nodes;		//	左子树节点个数
	if (last_depth_nodes <= pow(2, depth - 2)) {
		left_num_nodes = num - pow(2, depth - 2);
	}
	else {
		left_num_nodes = pow(2, depth - 1) - 1;
	}
	int root = inl + left_num_nodes;		//	根节点的索引
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