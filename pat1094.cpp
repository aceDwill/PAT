/*
	思路：1.用结构体node来存储输入数据
	      2.用generation_pop来存储具体代数（数组下标表示）有多少人
           3.用generation_ref来存储节点（数组下标表示）是第几代
		  4.在bfs遍历过程中更新generation_pop和generation_ref
		  5.对generation_pop数组进行迭代，输出最多人数及第几代
*/


#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct node{
	vector<int> children;
}Tree[100];

int generation_pop[100] = { 0 };		//	每代人数初始为零
int generation_ref[100] = { 0 };		//	编号为下标的人的具体代数，如genertion_ref[1] = 1,
									//	表示节点1号是第一代

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