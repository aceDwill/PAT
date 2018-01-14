/*
	思路：通过深度遍历优先方法遍历树，在每个叶节点处计算价钱
		
	注：1.用cin输入会超时
		2.浮点数据类型用double，不要float，否则会出现计算错误
*/


#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

struct node{
	int amount = 0;
	vector<int> children;

}Tree[100010];

double total_sales = 0.0;
double price, rate;
void dfs(int root, int depth) {
	int len = Tree[root].children.size();		//	孩子节点个数
	if (len == 0) {
		total_sales += price *
			pow((1 + rate * 0.01), depth ) * Tree[root].amount;
	}
	else {
		for (int i = 0; i < len; i++) {
			dfs(Tree[root].children[i], depth + 1);
		}
	}
}

int main() {

	int N;
	cin >> N >> price >> rate;
	for (int i = 0; i < N; i++) {
		int k;
		scanf("%d", &k);
		if (k != 0) {
			for (int j = 0; j < k; j++) {
				int child;
				scanf("%d", &child);
				Tree[i].children.push_back(child);
			}
		}
		else{
			int amount;
			scanf("%d", &amount);
			Tree[i].amount = amount;
		}
	}
	dfs(0, 0);
	printf("%.1f", total_sales);

	return 0;
}