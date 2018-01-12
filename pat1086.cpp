/*
	思路：1.通过先序序列和中序序列建立二叉树
		  2.输出后序遍历序列

*/



#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

struct node{
	int value;
	node* left = NULL;
	node* right = NULL;
};

stack<int> origin;
vector<int> preorder, inorder, postorder;

void createBTree(node* &root, int prel, int prer, int inl, int inr) {
	if (prel > prer) return;
	root = new node();
	root->value = preorder[prel];
	int index = 0;
	while (inorder[index] != root->value) index++;		//	中序序列中根节点位置
	int left_num = index - inl;		//	左子树节点个数
	createBTree(root->left, prel + 1, prel + left_num, inl, index - 1);
	createBTree(root->right, prel + left_num + 1, prer, index + 1, inr);

}

//	后序遍历
void postOrder(node * root) {
	if (root == NULL) return;
	postOrder(root->left);
	postOrder(root->right);
	postorder.push_back(root->value);
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < 2 * N; i++) {
		string s;
		cin >> s;
		if (s != "Pop") {
			int value;
			cin >> value;
			origin.push(value);
			preorder.push_back(value);
		}
		else {
			inorder.push_back(origin.top());
			origin.pop();
		}
	}
	node* root = NULL;
	createBTree(root, 0, N - 1, 0, N - 1);
	postOrder(root);
	cout << postorder[0];
	for (int i = 1; i < N; i++) {
		cout << " " << postorder[i];
	}
	return 0;
}