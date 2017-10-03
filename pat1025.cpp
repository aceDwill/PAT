/*
	思路：1.用结构体存储考生信息
		  2.用sort进行排序
*/


#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct testee
{
	string regist_num;
	int score;
	int final_rank = 1;
	int local_num;
	int local_rank = 1;
};

bool comp(testee t1, testee t2) {
	if (t1.score == t2.score) {
		return t1.regist_num < t2.regist_num;
	}
	else {
		return t1.score > t2.score;
	}
}

int main() {

	int N;
	cin >> N;
	vector<testee> testees;
	//	区域考生的起始和终止索引
	int left = 0;
	int right = 0;
	for (int i = 1; i <= N; i++) {
		
		int K;
		cin >> K;
		right += K;
		for (int j = 0; j < K; j++) {
			testee t;
			cin >> t.regist_num >> t.score;
			t.local_num = i;
			testees.push_back(t);

		}
		sort(testees.begin() + left, testees.begin() + right, comp);
		//	排序后从第二个考生开始若分数相等，则排名等于前一名考生排名，否则排名等于索引
		for (int k = left + 1; k < right; k++) {
			if (testees[k].score == testees[k - 1].score) {
				testees[k].local_rank = testees[k - 1].local_rank;
			}
			else {
				testees[k].local_rank = k - left + 1;
			}
		}
		left += K;

	}
	cout << testees.size() << endl;
	sort(testees.begin(), testees.end(), comp);
	cout << testees[0].regist_num << " " << testees[0].final_rank <<
		" " << testees[0].local_num << " " << testees[0].local_rank << endl;
	for (int i = 1; i < testees.size(); i++) {
		if (testees[i].score == testees[i - 1].score) {
			testees[i].final_rank = testees[i - 1].final_rank;
		}
		else {
			testees[i].final_rank = i + 1;
		}
		cout << testees[i].regist_num << " " << testees[i].final_rank <<
			" " << testees[i].local_num << " " << testees[i].local_rank << endl;
	}



	return 0;
}