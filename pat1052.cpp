/*
	思路：1.通过结构体数组存储输入数据
		  2.遍历一遍链表，遇到过的节点用vector保存
		  3.对vector进行排序
	注意：当vector为空时，输出0 -1
*/



#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct node{
	int address;
	int key;
	int next;

}llist[100000];

bool cmp(node n1, node n2) {
	return n1.key < n2.key;
}

int main() {

	int N, head_node;
	cin >> N >> head_node;
	int addr, key, next;
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &addr, &key, &next);		//	不用cin，防止输入超时
		llist[addr].address = addr;
		llist[addr].key = key;
		llist[addr].next = next;
	}
	vector<node> v;
	for (int address = head_node; address != -1; address = llist[address].next) {
		v.push_back(llist[address]);
	}
	sort(v.begin(), v.end(), cmp);
	int len = v.size();
	if (len == 0) {
		printf("0 -1");
		return 0;
	}
	printf("%d %05d\n", len, v[0].address);
	printf("%05d %d", v[0].address, v[0].key);
	for (int i = 1; i < len; i++) {
		printf(" %05d\n", v[i].address);
		printf("%05d %d", v[i].address, v[i].key);
	}
	printf(" -1");
	return 0;
}