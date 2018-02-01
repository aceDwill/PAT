/*
	思路：1.用结构体student存储输入数据
		  2.对各课程进行排序，将排名情况存入Rank数组中
		  3.为便于按a,c,m,e课程进行排序Rank[id][0]...Rank[id][3]依次存储a,c,m,e课程排名
		  4.在查询过程中按要求输出最好排名

*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct student{

	int id;
	int grades[4];
};

int course;		//	代指具体课程
char courses[4] = { 'A','C','M','E' };
bool comp(student s1, student s2) {
	return s1.grades[course] > s2.grades[course];
}

int Rank[1000000][4] = {0};		//	存储每个学生的排名情况，若其中排名为0则该学生不存在

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
		sort(students.begin(), students.end(), comp);	//	对课程i进行排名
		//	存储学生各课程的排名情况
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