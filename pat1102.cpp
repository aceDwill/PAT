/*
	思路：1.用结构体数组存储输入数据
		  2.由左右节点没出现的节点为根节点的原理，找出根节点
		  3.通过层序反转遍历，中序反转遍历输出结果

*/


#include<iostream>
#include<queue>
using namespace std;

struct node{
	int left = -1;
	int right = -1;
}Tree[10];

//	将输入的char类型左右子节点，转化为int型，无子节点则赋值为-1
int transfer(char c) {
	if (c == '-') {
		return -1;
	}
	else {
		return c - '0';
	}
}

//	层序反转遍历
void level_invert_order(int root) {
	queue<int> q;
	q.push(root);
	cout << root;
	while (!q.empty()){
		int pop_node = q.front();
		int l = Tree[pop_node].left;
		int r = Tree[pop_node].right;
		if (r != -1) {
			cout << " " << r;
			q.push(r);
		}
		if (l != -1) {
			cout << " " << l;
			q.push(l);
		}
		q.pop();
	}
}

//	中序反转遍历
bool first_out = true;
void inorder_invert(int root) {
	if (root == -1) return;
	inorder_invert(Tree[root].right);
	//	第一次输出和后面几次输出有一些区别
	if (first_out) {
		cout << root;
		first_out = false;
	}
	else {
		cout << " " << root;
	}
	inorder_invert(Tree[root].left);
}

int main() {
	
	int exist_node[10] = { 0 };
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		char left, right;
		cin >> left >> right;
		Tree[i].left = transfer(left);
		Tree[i].right = transfer(right);
		node n = Tree[i];

		if (n.left != -1) exist_node[n.left]++;
		if (n.right != -1) exist_node[n.right]++;
	}
	int root = 0;		
	//	找出root节点，即孩子节点中没出现过的节点

	for (root; root < N; root++) {
		if (exist_node[root] == 0) {
			break;
		}
	}
	level_invert_order(root);
	cout << endl;
	inorder_invert(root);
	return 0;
}