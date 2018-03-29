/*
	˼·�����ն�Ӧ���룬��д��Ӧ�����߼������������м�¼
	ע��1.���Ե�6���г�ʱ��Ӧ��cin��cout��Ϊscanf��printf
		2.printf���string�������ݻ�����

*/


#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct Record{
	int ID;
	string name;
	int grade;
};

bool comp1(Record r1, Record r2) {
	return r1.ID < r2.ID;
}

bool comp2(Record r1, Record r2) {
	if (r1.name != r2.name) {
		return r1.name < r2.name;
	}
	else {
		return r1.ID < r2.ID;
	}
}
bool comp3(Record r1, Record r2) {
	if (r1.grade != r2.grade) {
		return r1.grade < r2.grade;
	}
	else {
		return r1.ID < r2.ID;
	}
}

int main() {

	int N, C;
	cin >> N >> C;
	vector<Record> records;
	Record r;
	for (int i = 0; i < N; i++) {
		cin >> r.ID >> r.name >> r.grade;
		records.push_back(r);
	}
	switch (C)
	{
	case 1: sort(records.begin(), records.end(), comp1); break;
	case 2: sort(records.begin(), records.end(), comp2); break;
	case 3: sort(records.begin(), records.end(), comp3);
	}

	for (int i = 0; i < N; i++) {
		printf("%06d ", records[i].ID);
		cout << records[i].name << " " << records[i].grade << endl;
	}
	return 0;
}