/*
	思路：就是一般的平衡二叉树建立过程，网上可以搜一下教程

*/

#include<iostream>
#include<algorithm>
using namespace std;

struct node{
	
	int value, depth = 1;
	node* left = NULL;
	node* right = NULL;
};

int getHight(node* root) {

	if (root == NULL) {
		return 0;
	}
	else {
		return root->depth;
	}
}

void updateHight(node* root) {
	root->depth = max(getHight(root->left),
		getHight(root->right)) + 1;
}

int getBalanceFactor(node* root) {
	return getHight(root->left) - getHight(root->right);
}

void leftRotate(node* &root) {
	node* temp = root->right;
	root->right = temp->left;
	temp->left = root;
	updateHight(root);
	updateHight(temp);
	root = temp;
}

void rightRotate(node* &root) {
	node* temp = root->left;
	root->left = temp->right;
	temp->right = root;
	updateHight(root);
	updateHight(temp);
	root = temp;
}

void insert(node* &root, int value) {
	
	if (root == NULL) {
		root = new node();
		root->value = value;
	}
	else if (value < root->value) {
		insert(root->left, value);
		updateHight(root);
		if (getBalanceFactor(root) == 2) {
			if (getBalanceFactor(root->left) == 1) {
				rightRotate(root);
			}
			else {
				leftRotate(root->left);
				rightRotate(root);
			}

		}
	}
	else {
		insert(root->right, value);
		updateHight(root);
		if (getBalanceFactor(root) == -2) {
			if (getBalanceFactor(root->right) == -1) {
				leftRotate(root);
			}
			else {
				rightRotate(root->right);
				leftRotate(root);
			}
		}
	}
}


int main() {

	int N;
	scanf("%d", &N);
	node* root = NULL;
	for (int i = 0; i < N; i++) {
		int k;
		scanf("%d", &k);
		insert(root, k);
	}

	printf("%d", root->value);
	return 0;
}