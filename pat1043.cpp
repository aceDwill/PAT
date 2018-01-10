/*
	思路：1.将输入数字按二叉排序树过程建树
		  2.通过将先序遍历或先序镜像遍历得到序列与输出序列比较，看是否一致
		  3.若一致，则输出后序遍历序列或后序镜像遍历序列，不一致输出NO

*/



#include<iostream>
#include<vector>
using namespace std;

struct node {
	int key;
	node* left = NULL;
	node* right = NULL;
};

//	BST插入函数
void insert(int key, node* &root) {
	if (root == NULL) {
		root = new node;
		root->key = key;
	}
	else if (key < root->key) {
		insert(key, root->left);
	}
	else {
		insert(key, root->right);
	}
}

//	记录先序遍历，先序镜像遍历，后序遍历，后序镜像遍历
vector<int> preOrder, preMirrorOrder, postOrder, postMirrorOrder;

//	先序遍历
void pre_order(node* root) {
	if (root == NULL) return;

	preOrder.push_back(root->key);
	pre_order(root->left);
	pre_order(root->right);
}

//	先序镜像遍历

void pre_mirror_order(node* root) {
	if (root == NULL) return;

	preMirrorOrder.push_back(root->key);
	pre_mirror_order(root->right);
	pre_mirror_order(root->left);
}

//	后序遍历
void post_order(node* root) {
	if (root == NULL) return;

	post_order(root->left);
	post_order(root->right);
	postOrder.push_back(root->key);
}


//	后序镜像遍历
void post_mirror_order(node* root) {
	if (root == NULL) return;

	post_mirror_order(root->right);
	post_mirror_order(root->left);
	postMirrorOrder.push_back(root->key);
}


int main() {

	int N;
	cin >> N;
	node* root = NULL;
	int data;
	vector<int> origin;
	for (int i = 0; i < N; i++) {
		cin >> data;
		origin.push_back(data);
		insert(data, root);
	}

	pre_order(root);
	pre_mirror_order(root);
	if (preOrder == origin) {
		cout << "YES" << endl;
		post_order(root);
		cout << postOrder[0];
		for (int i = 1; i < N; i++) {
			cout << " " << postOrder[i];
		}
	}
	else if (preMirrorOrder == origin) {
		cout << "YES" << endl;
		post_mirror_order(root);
		cout << postMirrorOrder[0];
		for (int i = 1; i < N; i++) {
			cout << " " << postMirrorOrder[i];
		}
	}
	else {
		cout << "NO";
	}

	return 0;
}