/*
	˼·��1.���ݺ��������ȷ�����ڵ㣬�ݹ���
		  2.�ڵݹ��ʱ��˳�����λ�ò���������2*i+1����2*i+2�����������˳��
*/

#include<iostream>
using namespace std;

int result[1000000] = { 0 };		//	���result������Ҫ�㹻�󣬷����������ֶδ���
int inorder[30];
int postorder[30];

void levelorder(int postion, int postl, int postr, int inl, int inr) {
	if (postl > postr) {
		return;
	}

	int root = postorder[postr];
	int i = inl;
	while (root != inorder[i]) {
		++i;
	}
	int numleft = i - inl;		//	�������ڵ����
	result[postion] = root;		//	�����ڵ㰴���������˳�����result������

	levelorder(2 * postion + 1, postl, postl + numleft - 1, inl, i - 1);
	levelorder(2 * postion + 2, postl + numleft, postr - 1, i + 1, inr);
}

int main() {

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		scanf("%d", &postorder[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &inorder[i]);
	}
	levelorder(0, 0, N - 1, 0, N - 1);
	cout << result[0];
	for (int i = 1, cnt = 1; cnt < N; i++) {
		if (result[i] != 0) {
			cout << " " << result[i];
			++cnt;
		}
	}
	return 0;

}