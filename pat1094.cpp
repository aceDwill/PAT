/*
	˼·��1.�ýṹ��node���洢��������
	      2.��generation_pop���洢��������������±��ʾ���ж�����
           3.��generation_ref���洢�ڵ㣨�����±��ʾ���ǵڼ���
		  4.��bfs���������и���generation_pop��generation_ref
		  5.��generation_pop������е������������������ڼ���
*/


#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct node{
	vector<int> children;
}Tree[100];

int generation_pop[100] = { 0 };		//	ÿ��������ʼΪ��
int generation_ref[100] = { 0 };		//	���Ϊ�±���˵ľ����������genertion_ref[1] = 1,
									//	��ʾ�ڵ�1���ǵ�һ��

void bfs(int root) {
	
	queue<int> q;
	q.push(root);
	generation_pop[root] += 1;
	generation_ref[root] = 1;
	while (!q.empty()){
		int now = q.front();
		q.pop();
		int len = Tree[now].children.size();
		for (int i = 0; i < len; i++) {
			int child = Tree[now].children[i];
			generation_ref[child] = generation_ref[now] + 1;
			generation_pop[generation_ref[child]] += 1;
			q.push(child);
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
	bfs(1);
	int max_pop = 0;
	int max_pop_generation = 0;
	for (int i = 1; i < N + 1; i++) {
		if (generation_pop[i] > max_pop) {
			max_pop = generation_pop[i];
			max_pop_generation = i;
		}
	}

	printf("%d %d", max_pop, max_pop_generation);
	return 0;
}