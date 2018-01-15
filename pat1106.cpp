/*
	Ë¼Â·£º¼ûpat1090

*/

#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

struct node{
	vector<int> children;
}Tree[100010];

int min_depth = 100010;
int num = 0;

void dfs(int root, int depth) {
	
	int len = Tree[root].children.size();
	if (len == 0) {
		if (depth < min_depth) {
			min_depth = depth;
			num = 1;
		}
		else if (depth == min_depth){
			num += 1;
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
	for (int i = 0; i < N; i++) {
		int k, child;
		scanf("%d", &k);
		if (k != 0) {
			for (int j = 0; j < k; j++) {
				scanf("%d", &child);
				Tree[i].children.push_back(child);
			}
		}
	}
	
	dfs(0, 0);
	double result = price * pow((1 + rate * 0.01), min_depth);
	printf("%.4f %d", result, num);

	return 0;
}