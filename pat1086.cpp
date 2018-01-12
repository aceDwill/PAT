/*
	˼·��1.ͨ���������к��������н���������
		  2.��������������

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
	while (inorder[index] != root->value) index++;		//	���������и��ڵ�λ��
	int left_num = index - inl;		//	�������ڵ����
	createBTree(root->left, prel + 1, prel + left_num, inl, index - 1);
	createBTree(root->right, prel + left_num + 1, prer, index + 1, inr);

}

//	�������
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