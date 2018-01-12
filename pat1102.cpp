/*
	˼·��1.�ýṹ������洢��������
		  2.�����ҽڵ�û���ֵĽڵ�Ϊ���ڵ��ԭ���ҳ����ڵ�
		  3.ͨ������ת����������ת����������

*/


#include<iostream>
#include<queue>
using namespace std;

struct node{
	int left = -1;
	int right = -1;
}Tree[10];

//	�������char���������ӽڵ㣬ת��Ϊint�ͣ����ӽڵ���ֵΪ-1
int transfer(char c) {
	if (c == '-') {
		return -1;
	}
	else {
		return c - '0';
	}
}

//	����ת����
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

//	����ת����
bool first_out = true;
void inorder_invert(int root) {
	if (root == -1) return;
	inorder_invert(Tree[root].right);
	//	��һ������ͺ��漸�������һЩ����
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
	//	�ҳ�root�ڵ㣬�����ӽڵ���û���ֹ��Ľڵ�

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