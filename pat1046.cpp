/*
	思路：1.将所有距离加起来，和为sum
          2.将1号点到第i个点的下一个点的距离存储到distance[i]
          3.计算两个点之间的距离，即distance[b - 1] - distance[a - 1]
          4.比较sum和3中距离，输出最小结果
          

		 PS：如果数组距离进行处理，每次迭代计算a到b的距离，测试点2会出现运行超时
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