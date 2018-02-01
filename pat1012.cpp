/*
	˼·��1.�ýṹ��student�洢��������
		  2.�Ը��γ̽������򣬽������������Rank������
		  3.Ϊ���ڰ�a,c,m,e�γ̽�������Rank[id][0]...Rank[id][3]���δ洢a,c,m,e�γ�����
		  4.�ڲ�ѯ�����а�Ҫ������������

*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct student{

	int id;
	int grades[4];
};

int course;		//	��ָ����γ�
char courses[4] = { 'A','C','M','E' };
bool comp(student s1, student s2) {
	return s1.grades[course] > s2.grades[course];
}

int Rank[1000000][4] = {0};		//	�洢ÿ��ѧ�����������������������Ϊ0���ѧ��������

int main() {

	vector<student> students;
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		student stu;
		cin >> stu.id >> stu.grades[1] >> stu.grades[2] >> stu.grades[3];
		stu.grades[0] = stu.grades[1] + stu.grades[2] + stu.grades[3];
		students.push_back(stu);
	}

	for (int i = 0; i < 4; i++) {
		course = i;
		sort(students.begin(), students.end(), comp);	//	�Կγ�i��������
		//	�洢ѧ�����γ̵��������
		Rank[students[0].id][i] = 1;
		for (int r = 1; r < N; r++) {
			if (students[r].grades[i] == students[r - 1].grades[i]) {
				Rank[students[r].id][i] = Rank[students[r - 1].id][i];
			}
			else {
				Rank[students[r].id][i] = r + 1;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		int id, course = 0;
		cin >> id;
		if (Rank[id][0] == 0) {
			cout << "N/A" << endl;
			continue;
		}
		else {
			for (int c = 0; c < 4; c++) {
				if (Rank[id][c] < Rank[id][course]) {
					course = c;
				}
			}
		}
		cout << Rank[id][course] << " " << courses[course] << endl;
	}
	
	return 0;
}