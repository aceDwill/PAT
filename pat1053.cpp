/*
	思路：1.用结构体数组存储节点，用数组下标表示节点编号
		  2.对树进行深度遍历，并在遍历过程保存权值

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct node {

	int weight;
	vector<int> children;

} Tree[200];

bool comp(int n1, int n2) {
	return Tree[n1].weight > Tree[n2].weight;
}

int N, M, S;		//	定义节点数，非叶节点数，给定权值
void maxChildOrder(int root,int sum, vector<node> track) {		//	track记录节点路径
	sum += Tree[root].weight;
	if (sum > S || (sum == S && !Tree[root].children.empty())) {
		return;		//	如果加上该子节点权值超过给定权值，或者等于权值还有子节点，则跳过这个子节点
	}
	if (root != 0) {
		track.push_back(Tree[root]);	//	把除了根节点的计算过的节点记录下来
	}
	vector<int> curr_children = Tree[root].children;
	if (curr_children.size() != 0) {		//	当存在子节点的时候
		sort(curr_children.begin(), curr_children.end(),comp);		//	将孩子节点按权值从大到小排序
		for (int i = 0; i < curr_children.size(); i++) {
			maxChildOrder(curr_children[i], sum, track);
		}
	}
	else {
		if (sum == S) {
			cout << Tree[0].weight;
			for (int i = 0; i < track.size(); i++) {		//	输出记录权值
				cout << " " << track[i].weight;
			}
			cout << endl;
		}
	}
}
int main() {

	
	cin >> N >> M >> S;
	for (int i = 0; i < N; i++) {
		cin >> Tree[i].weight;
	}
	for (int i = 0; i < M; i++) {
		int addr, K;
		cin >> addr >> K;
		for (int j = 0; j < K; j++) {
			int ID;
			cin >> ID;
			Tree[addr].children.push_back(ID);
		}
	} 
	vector<node> track;
	maxChildOrder(0, 0, track);
	return 0;
}