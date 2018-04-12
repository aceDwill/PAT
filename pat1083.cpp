/*
	思路：1.用一个结构体student存储输入数据
           2.根据学生分数对所有学生进行排名
		   3.输出在要求范围成绩内的学生信息

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

	bool has_print_stu = false;	//	表示没有输出过学生信息
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