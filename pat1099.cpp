/*
	思路：通过中序遍历建树后通过层序遍历输出结果

*/


#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct node{
	int value;
	int left;
	int right;
}Tree[110];

vector<int> origin;
int index = 0;
void inorder(int root) {
	if (root == -1) return;
	inorder(Tree[root].left);
	Tree[root].value = origin[index++];
	inorder(Tree[root].right);
}

queue<int> q;
void bfs(int root) {
	q.push(root);
	printf("%d", Tree[root].value);
	while (!q.empty()){
		int now = q.front();
		q.pop();
		int left = Tree[now].left;
		int right = Tree[now].right;
		if (left != -1) {
			q.push(left);
			printf(" %d", Tree[left].value);
		}
		if (right != -1) {
			q.push(right);
			printf(" %d", Tree[right].value);
		}
	}
}

int main() {

	int N;
	scanf("%d", &N);
	origin.resize(N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &Tree[i].left, &Tree[i].right);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &origin[i]);
	}

	sort(origin.begin(), origin.end());
	inorder(0);
	bfs(0);
	return 0;
}