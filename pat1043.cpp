/*
	˼·��1.���������ְ��������������̽���
		  2.ͨ�����������������������õ�������������бȽϣ����Ƿ�һ��
		  3.��һ�£����������������л������������У���һ�����NO

*/



#include<iostream>
#include<vector>
using namespace std;

struct node {
	int key;
	node* left = NULL;
	node* right = NULL;
};

//	BST���뺯��
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

//	��¼��������������������������������������
vector<int> preOrder, preMirrorOrder, postOrder, postMirrorOrder;

//	�������
void pre_order(node* root) {
	if (root == NULL) return;

	preOrder.push_back(root->key);
	pre_order(root->left);
	pre_order(root->right);
}

//	���������

void pre_mirror_order(node* root) {
	if (root == NULL) return;

	preMirrorOrder.push_back(root->key);
	pre_mirror_order(root->right);
	pre_mirror_order(root->left);
}

//	�������
void post_order(node* root) {
	if (root == NULL) return;

	post_order(root->left);
	post_order(root->right);
	postOrder.push_back(root->key);
}


//	���������
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