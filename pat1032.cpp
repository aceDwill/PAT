/*
	˼·��1.�ýṹ������洢���ݣ��±��ʾ��ַ
		  2.������һ���ַ���������־��Ϊtrue
		  3.�����ڶ����ַ�����������־Ϊtrue�������ַ
*/

#include<iostream>
using namespace std;

struct cnode {
	char data;
	int next;
	bool flag = false;	//	��ʾ�ڵ㻹δ�����ʹ�
}llist[100000];
int main() {
 
	int addr1, addr2, N;
	cin >> addr1 >> addr2 >> N;
	int address, next;
	char data;
	for (int i = 0; i < N; i++) {
		scanf("%d %c %d", &address, &data, &next);		//	��cin���룬���һ���Ե�ᳬʱ
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