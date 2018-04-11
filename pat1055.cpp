/*
	˼·���Ȱ��������������ٸ��ݾ����ѯ���
	ע��1��2���Ե��������

*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct Rich{
	string name;
	int age;
	int worth;
};

vector<Rich> rich_men, rich_men_100;	//	���еĸ����;���ĳ������ӵ���ʲ���ǰһ��ɸѡ�ĸ���
int age_rich_num[300] = { 0 };		//	ͳ��ĳ���������������

void print_result(int max_num, int amin, int amax) {
	vector<Rich> search_rich_men;
	for (int i = 0; i < rich_men_100.size(); i++) {
		if (rich_men_100[i].age >= amin && rich_men_100[i].age <= amax) {
			search_rich_men.push_back(rich_men[i]);
		}
	}
	if (search_rich_men.size() == 0) {
		cout << "None" << endl;
	}
	else {
		for (int i = 0; i < search_rich_men.size() && i < max_num; i++) {
			cout << search_rich_men[i].name << " "
				<< search_rich_men[i].age << " " << search_rich_men[i].worth << endl;
		}
	}
}

bool comp(Rich r1, Rich r2) {
	
	if (r1.worth != r2.worth) return r1.worth > r2.worth;
	else if (r1.age != r2.age) return r1.age < r2.age;
	else return r1.name < r2.name;
}


int main() {

	int N, K;
	cin >> N >> K;
	Rich r;
	for (int i = 0; i < N; i++) {
		cin >> r.name >> r.age >> r.worth;
		rich_men.push_back(r);
	}
	sort(rich_men.begin(), rich_men.end(), comp);

	for (int i = 0; i < N; i++) {
		if (age_rich_num[rich_men[i].age] < 100) {
			rich_men_100.push_back(rich_men[i]);
			age_rich_num[rich_men[i].age] ++;
		}
	}

	int max_num, amin, amax;
	for (int i = 1; i <= K; i++) {
		cin >> max_num >> amin >> amax;
		cout << "Case #" << i << ":" << endl;
		print_result(max_num, amin, amax);
	}


	return 0;
}