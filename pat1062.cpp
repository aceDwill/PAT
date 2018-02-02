/*
	˼·��1.�Ƚ�����ɼ���Ҫ���Ϊsages,nobleman,foolman,smallman������
	      2.�������˷ֱ�������������ɼ�

*/


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct person{

	int id;
	int vg;
	int tg;
};

bool comp(person p1, person p2) {
	int sum1 = p1.vg + p1.tg;
	int sum2 = p2.vg + p2.tg;
	if (sum1 != sum2) {
		return sum1 > sum2;		//	���ܳɼ��Ӵ�С����
	}
	else {
		if (p1.vg != p2.vg) {
			return p1.vg > p2.vg;			//	�ܳɼ���Ȱ�vg�Ӵ�С����
		}
		else {
			return p1.id < p2.id;			//	�ܳɼ���Ȳ���vg�ɼ���Ȱ�ѧ����С��������
		}
	}
}

int main() {

	vector<person> people[4];		//	people[0,1,2,3]�ֱ��ʾsages,noblemen,foolmen,smallmen

	int N, L, H;
	cin >> N >> L >> H;
	for (int i = 0; i < N; i++) {
		person p;
		cin >> p.id >> p.vg >> p.tg;
		if (p.vg >= H && p.tg >= H) {
			people[0].push_back(p);
		}
		else if (p.vg >= H && p.tg >= L) {
			people[1].push_back(p);
		}
		else if (p.vg >= p.tg && p.tg >= L) {
			people[2].push_back(p);
		}
		else if (p.vg >= L && p.tg >= L) {
			people[3].push_back(p);
			}
	}

	int numPerson = 0;
	for (int i = 0; i < 4; i++) {
		numPerson += people[i].size();
	}
	cout << numPerson << endl;

	for (int i = 0; i < 4; i++) {
		sort(people[i].begin(), people[i].end(), comp);
		for (int j = 0; j < people[i].size(); j++) {
			//	%08d  ��ֹѧ��ǰ����0�����
			printf("%08d %d %d\n", people[i][j].id, people[i][j].vg, people[i][j].tg);
		}
	}

	return 0;
}