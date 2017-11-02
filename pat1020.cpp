/*
	思路：1.根据后序和中序确定根节点，递归解决
		  2.在递归的时候，顺便更新位置参数，根据2*i+1，和2*i+2决定层序遍历顺序
*/

#include<iostream>
using namespace std;

int result[1000000] = { 0 };		//	存放result的数组要足够大，否则第五点会出现段错误
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
	int numleft = i - inl;		//	左子树节点个数
	result[postion] = root;		//	将根节点按层序遍历的顺序放在result数组中

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