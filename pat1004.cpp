/*
	˼·��1.�ýṹ��node�洢��������
	      2.��dfs�������̼�¼ÿ��Ҷ�ڵ�����Լ������߶�
*/


#include<iostream>
#include<vector>
using namespace std;

struct node{
	vector<int> children;
}Tree[100];

int max_depth = 0;
int generation_pop[100] = { 0 };
void dfs(int root, int depth) {
	int len = Tree[root].children.size();
	//	û�к��ӽڵ㼴�ڵ���Ҷ�ڵ�����
	if (len == 0) {
		generation_pop[depth] += 1;
		max_depth = depth > max_depth ? depth : max_depth;
	}
	else {
		for (int i = 0; i < len; i++) {
			dfs(Tree[root].children[i], depth + 1);
		}
	}
}

int main() {

	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int ID, K, child;
		scanf("%d %d", &ID, &K);
		for (int j = 0; j < K; j++) {
			scanf("%d", &child);
			Tree[ID].children.push_back(child);
		}
	}
	dfs(1, 0);
	printf("%d", generation_pop[0]);
	for (int i = 1; i <= max_depth; i++) {
		printf(" %d", generation_pop[i]);
	}
	return 0;
}