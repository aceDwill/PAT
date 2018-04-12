/*
	˼·��1.��һ���ṹ��student�洢��������
           2.����ѧ������������ѧ����������
		   3.�����Ҫ��Χ�ɼ��ڵ�ѧ����Ϣ

*/


#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct student{

	string name;
	string ID;
	int grade;
};

bool comp(student s1, student s2) {
	return s1.grade > s2.grade;
}

int main() {

	int N;
	vector<student> students;
	cin >> N;
	student s;
	for (int i = 0; i < N; i++) {
		cin >> s.name >> s.ID >> s.grade;
		students.push_back(s);
	}
	int grade1, grade2;
	cin >> grade1 >> grade2;
	
	sort(students.begin(), students.end(), comp);

	bool has_print_stu = false;	//	��ʾû�������ѧ����Ϣ
	for (int i = 0; i < N; i++) {
		if (students[i].grade >= grade1 && students[i].grade <= grade2) {
			cout << students[i].name << " " << students[i].ID << endl;
			has_print_stu = true;
		}
	}
	if (!has_print_stu) {
		cout << "NONE";
	}
	return 0;
}