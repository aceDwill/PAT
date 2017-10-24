/*
	思路：1.用结构体数组存储数据，下标表示地址
		  2.遍历第一个字符串，将标志改为true
		  3.遍历第二个字符串，遇到标志为true的输出地址
*/

#include<iostream>
using namespace std;

struct cnode {
	char data;
	int next;
	bool flag = false;	//	表示节点还未被访问过
}llist[100000];
int main() {
 
	int addr1, addr2, N;
	cin >> addr1 >> addr2 >> N;
	int address, next;
	char data;
	for (int i = 0; i < N; i++) {
		scanf("%d %c %d", &address, &data, &next);		//	用cin输入，最后一测试点会超时
		llist[address].data = data;
		llist[address].next = next;
	}
	int addr;
	for (addr = addr1; addr != -1;) {
		llist[addr].flag = true;
		addr = llist[addr].next;
	}

	for (addr = addr2; addr != -1;) {
		if (llist[addr].flag == true) {
			printf("%05d", addr);
			break;
		}
		addr = llist[addr].next;
	}
	if (addr == -1){
		cout << "-1";
	}

	return 0;
}