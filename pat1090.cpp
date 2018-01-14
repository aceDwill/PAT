/*
	思路：运用树的dfs遍历，找出树的最大高度，和具有相同最大高度的路径数

*/

#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

struct node{
	vector<int> children;
}Tree[100010];

int max_depth = 0, num = 0;
void dfs(int root, int depth) {
	int len = Tree[root].children.size();
	if (len == 0) {
		if (depth > max_depth) {
			max_depth = depth;
			num = 1;		//	刷新相同最大高度的路径数
		}
		else if (depth == max_depth) {
			num++;
		}
	}
	else {
		for (int i = 0; i < len; i++) {
			dfs(Tree[root].children[i], depth + 1);
		}
	}
}

int main() {

	int N;
	double price, rate;
	scanf("%d %lf %lf", &N, &price, &rate);
	int root;
	for (int i = 0; i < N; i++) {
		int parent;
		scanf("%d", &parent);
		if (parent != -1) {
			Tree[parent].children.push_back(i);
		}
		else {
			root = i;
		}
		
	}
	dfs(root, 0);
	double result = price * pow((1 + rate * 0.01), max_depth);
	printf("%.2f %d", result, num);
	return 0;
}