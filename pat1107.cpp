/*
	思路：并查集的运用，可以搜一下网上教程

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int father[1010] = { 0 };
int isRoot[1010] = { 0 };
int hobby[1010] = { 0 };

bool comp(int a, int b) {
	return a >= b;
}

int findFather(int x) {

	int a = x;
	while (x != father[x]) {
		x = father[x];
	}

	//	路径压缩
	while (a != father[a]){
		int z = a;
		a = father[a];
		father[z] = x;
	}

	return x;
}

void Union(int a, int b) {
	int FAa = findFather(a);
	int FAb = findFather(b);
	if (FAa != FAb) {
		father[FAb] = FAa;
	}
}

int main() {

	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		father[i] = i;
	}
	for (int i = 1; i <= N; i++) {
		int K,h;
		scanf("%d: ", &K);
		for (int j = 0; j < K; j++) {
			scanf("%d", &h);
			if (hobby[h] == 0) {
				hobby[h] = i;
			}
			Union(findFather(hobby[h]), i);
		}
	}
	
	for (int i = 1; i <= 1010; i++) {
		isRoot[findFather(i)] ++;
	}
	vector<int> result;
	for (int i = 1; i <= N; i++) {
		if (isRoot[i] != 0) {
			result.push_back(isRoot[i]);
		}
	}

	sort(result.begin(), result.end(), comp);
	printf("%d\n", result.size());
	printf("%d", result[0]);
	for (int i = 1; i < result.size(); i++) {
		printf(" %d", result[i]);
	}

	return 0;
}