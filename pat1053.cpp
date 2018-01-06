/*
	˼·��1.�ýṹ������洢�ڵ㣬�������±��ʾ�ڵ���
		  2.����������ȱ��������ڱ������̱���Ȩֵ

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

int N, M, S;		//	����ڵ�������Ҷ�ڵ���������Ȩֵ
void maxChildOrder(int root,int sum, vector<node> track) {		//	track��¼�ڵ�·��
	sum += Tree[root].weight;
	if (sum > S || (sum == S && !Tree[root].children.empty())) {
		return;		//	������ϸ��ӽڵ�Ȩֵ��������Ȩֵ�����ߵ���Ȩֵ�����ӽڵ㣬����������ӽڵ�
	}
	if (root != 0) {
		track.push_back(Tree[root]);	//	�ѳ��˸��ڵ�ļ�����Ľڵ��¼����
	}
	vector<int> curr_children = Tree[root].children;
	if (curr_children.size() != 0) {		//	�������ӽڵ��ʱ��
		sort(curr_children.begin(), curr_children.end(),comp);		//	�����ӽڵ㰴Ȩֵ�Ӵ�С����
		for (int i = 0; i < curr_children.size(); i++) {
			maxChildOrder(curr_children[i], sum, track);
		}
	}
	else {
		if (sum == S) {
			cout << Tree[0].weight;
			for (int i = 0; i < track.size(); i++) {		//	�����¼Ȩֵ
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