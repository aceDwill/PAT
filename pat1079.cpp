/*
	˼·��ͨ����ȱ������ȷ�������������ÿ��Ҷ�ڵ㴦�����Ǯ
		
	ע��1.��cin����ᳬʱ
		2.��������������double����Ҫfloat���������ּ������
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
	int len = Tree[root].children.size();		//	���ӽڵ����
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