/*
	思路：1.先将输入成绩按要求分为sages,nobleman,foolman,smallman四种人
	      2.对四种人分别进行排序后输出成绩

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
		return sum1 > sum2;		//	按总成绩从大到小排序
	}
	else {
		if (p1.vg != p2.vg) {
			return p1.vg > p2.vg;			//	总成绩相等按vg从大到小排序
		}
		else {
			return p1.id < p2.id;			//	总成绩相等并且vg成绩相等按学号由小到大排序
		}
	}
}

int main() {

	vector<person> people[4];		//	people[0,1,2,3]分别表示sages,noblemen,foolmen,smallmen

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
			//	%08d  防止学号前面有0的情况
			printf("%08d %d %d\n", people[i][j].id, people[i][j].vg, people[i][j].tg);
		}
	}

	return 0;
}