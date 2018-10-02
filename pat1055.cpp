/*
	˼·���Ȱ��������������ٸ��ݾ����ѯ���
	ע������ÿ�β�ѯ�������ᳬ��100�����Խ�ĳ�������ʲ���100�Ժ������ȥ

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
int age_rich_num[1000] = { 0 };		//	ͳ��ĳ���������������



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
		int printNum = 0;
		for (int j = 0; j < rich_men_100.size() && printNum < max_num; j++) {
			Rich temp = rich_men_100[j];
			if (temp.age >= amin && temp.age <= amax) {
				cout << temp.name << " " << temp.age << " " << temp.worth << endl;
			
				printNum++;
			}		
		}

		if (printNum == 0) {
			cout << "None" << endl;
		}
	}


	return 0;
}