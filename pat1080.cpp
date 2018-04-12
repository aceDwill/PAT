/*
	思路：1.建立student结构体存储数据
	      2.对所有学生按照成绩规则排序
		  3.排在前面的同学按他的志愿选择优先录取
*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct student{

	int id;
	int gradeE;
	int gradeI;
	int total_grade;
	int choice[5] = { -1,-1,-1,-1,-1 };
};

bool comp1(student s1, student s2) {
	if (s1.total_grade != s2.total_grade) return s1.total_grade > s2.total_grade;
	else return s1.gradeE > s2.gradeE;
}

bool comp2(student s1, student s2) {
	return s1.id < s2.id;
}

int main() {

	int N, M, K;
	int quota[110];
	cin >> N >> M >> K;
	vector<student> students;
	vector<vector<student>> admission_result(110);	//	存储最后录取的学生
	for (int i = 0; i < M; i++) {
		cin >> quota[i];
	}
	student s;
	for (int i = 0; i < N; i++) {
		s.id = i;
		cin >> s.gradeE >> s.gradeI;
		s.total_grade = s.gradeE + s.gradeI;
		for (int j = 0; j < K; j++) {
			cin >> s.choice[j];
		}
		students.push_back(s);
	}

	sort(students.begin(), students.end(), comp1);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			int current_choice = students[i].choice[j];
			if (quota[current_choice] > 0) {	//	名额有剩，直接录取
				admission_result[current_choice].push_back(students[i]);
				quota[current_choice] --;
				break;
			}
			else if (quota[current_choice] == 0){
				student last_admit_stu = admission_result[current_choice].back();
				if (last_admit_stu.total_grade == students[i].total_grade &&
					last_admit_stu.gradeE == students[i].gradeE) {
					//	和录取的最后一位同学所有成绩相同，破格录取
					admission_result[current_choice].push_back(students[i]);
					break;
				}
			}

		}
	}

	for (int i = 0; i < M; i++) {
		if (admission_result[i].empty()) {
			cout << endl;
		}
		else {
			sort(admission_result[i].begin(), admission_result[i].end(), comp2);
			cout << admission_result[i][0].id;
			for (int j = 1; j < admission_result[i].size(); j++) {
				cout << " " << admission_result[i][j].id;
			}
			cout << endl;
		}
	}

	return 0;
}