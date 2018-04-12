/*
	思路：1.建立user结构体来存储相关数据
	      2.按照规则进行排序
*/


#include<iostream>
#include<algorithm>
using namespace std;

struct user{
	
	int id;
	int score[6] = { -1,-1,-1,-1,-1,-1 };
	int total_score = 0;
	int solved_problems = 0;	// 拿满分题目数
	bool has_passed = false;	//	表示全部题目没有通过编译，最后不输出信息
	int pat_rank = 1;			//	排名初始为1
}users[10010];

//	排序逻辑
bool comp(user u1, user u2) {
	if (u1.total_score != u2.total_score) return u1.total_score > u2.total_score;
	else if (u1.solved_problems != u2.solved_problems) 
		return u1.solved_problems > u2.solved_problems;
	else return u1.id < u2.id;

}

int main() {

	int N, K, M;
	cin >> N >> K >> M;
	int full_mark[6];
	for (int i = 1; i <= K; i++) {
		cin >> full_mark[i];
	}
	int user_id, problem_id, patial_score;
	for (int i = 0; i < M; i++) {
		cin >> user_id >> problem_id >> patial_score;
		users[user_id].id = user_id;
		//	提交过但通过编译分数要记为0
		if (patial_score == -1 && users[user_id].score[problem_id] == -1) {
			users[user_id].score[problem_id] = 0;
		}
		else if (patial_score >= users[user_id].score[problem_id]) {
			users[user_id].score[problem_id] = patial_score;	//	更新最高分数
			users[user_id].has_passed = true;	//	有题目通过编译
		}

	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (users[i].score[j] == full_mark[j]) {	//	有题目拿到满分
				users[i].solved_problems += 1;
			}
			if (users[i].score[j] != -1) {
				users[i].total_score += users[i].score[j];		//	累加总分
			}
		}
	}
	sort(users + 1, users + N + 1, comp);
	cout << users[1].pat_rank << " ";
	printf("%05d %d", users[1].id, users[1].total_score);
	for (int i = 1; i <= K; i++) {
		if (users[1].score[i] == -1) {
			cout << " -";
		}
		else {
			cout << " " << users[1].score[i];
		}
	}
	cout << endl;
	for (int i = 2; i <= N; i++) {
		if (users[i].total_score == users[i - 1].total_score) {
			users[i].pat_rank = users[i - 1].pat_rank;		//	总分相同，排名和前一位用户相同
		}
		else {
			users[i].pat_rank = i;
		}
		//	用户有题目通过编译
		if (users[i].has_passed) {
			cout << users[i].pat_rank << " ";
			printf("%05d %d", users[i].id, users[i].total_score);
			for (int j = 1; j <= K; j++) {
				if (users[i].score[j] == -1) {
					cout << " -";
				}
				else {
					cout << " " << users[i].score[j];
				}
			}
			cout << endl;
		}
		
	}
	return 0;
}