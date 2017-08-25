/*
	˼·��1.�����о������������Ϊsum
          2.��1�ŵ㵽��i�������һ����ľ���洢��distance[i]
          3.����������֮��ľ��룬��distance[b - 1] - distance[a - 1]
          4.�Ƚ�sum��3�о��룬�����С���
          

		 PS��������������д���ÿ�ε�������a��b�ľ��룬���Ե�2��������г�ʱ
*/
#include<iostream>
using namespace std;

int main() {

	int N;
	cin >> N;
	int distance[100000] = {0};
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		int temp;
		cin >> temp;
		sum += temp;
		distance[i] = sum;
	}
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		if (a > b) {
			int temp = a;
			a = b;
			b = temp;
		}
		int result;
		result = distance[b - 1] - distance[a - 1];
		result = result < (sum - result) ? result : (sum - result);
		cout << result << endl;
	}
	return 0;
}