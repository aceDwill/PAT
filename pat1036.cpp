/*
	思路：将男生和女生分别用两个vector存起来，分别排序即可
*/


#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct Student
{
	string name;
	char gender;
	string ID;
	int grade;
};

bool comp(Student s1, Student s2) {
	return s1.grade < s2.grade;
}
int main() {

	int N;
	cin >> N;
	vector<Student> vf, vm;
	for (int i = 0; i < N; i++) {
		string name, ID;
		char gender;
		int grade;
		cin >> name >> gender >> ID >> grade;
		Student s;
		s.name = name;
		s.gender = gender;
		s.ID = ID;
		s.grade = grade;
		if (gender == 'F') {
			vf.push_back(s);
		}
		else {
			vm.push_back(s);
		}
	}
	bool isabsent = false;
	
	if (vf.size() == 0) {
		cout << "Absent" << endl;
		isabsent = true;
	}
	else {
		sort(vf.begin(), vf.end(), comp);
		cout << vf[vf.size() - 1].name << ' ' << vf[vf.size() - 1].ID << endl;
	}
	if (vm.size() == 0) {
		cout << "Absent" << endl;
		isabsent = true;
	}
	else {
		sort(vm.begin(), vm.end(), comp);
		cout << vm[0].name << ' ' << vm[0].ID << endl;
	}
	if (isabsent == true) {
		cout << "NA";
	}
	else {
		cout << vf[vf.size() - 1].grade - vm[0].grade;
	}
	return 0;
}