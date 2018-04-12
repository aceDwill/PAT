"""
    思路：1.用一个字典存储数据，结构为
    {id:[总分，1题得分，...n题得分，拿满分题数，排名，有没有题目通过编译]}
         2.排序后输出结果
    注：测试点4超时
"""

N, K, M = [int(x) for x in input().split()]
full_mark = [int(x) for x in input().split()]  # 每道题的满分数

users_dic = {}

for i in range(N):
    users_dic[i + 1] = [0] + [-1] * K + [0, 1, 0]  # 每个用户的具体情况

for i in range(M):
    user_id, problem_id, partial_score_obtained \
        = [int(x) for x in input().split()]
    last_score = users_dic[user_id][problem_id]
    if partial_score_obtained == -1:
        users_dic[user_id][problem_id] = 0  # 如果提交过但未能通过编译分数记为0
    elif partial_score_obtained >= last_score:
        users_dic[user_id][problem_id] = partial_score_obtained
        users_dic[user_id][-1] = 1  # 表示有题目通过编译，要在最后排名输出该用户

for score in users_dic.values():
    for i in range(1, K + 1):
        if score[i] == full_mark[i - 1]:
            score[-3] += 1  # 满分题目数+1
        if score[i] != -1:
            score[0] += score[i]  # 累加总分

pat_rank = 1
# 按规则排序后，得到用户id的列表
users_id_sorted = sorted(users_dic, key=lambda x: (
    -users_dic[x][0], -users_dic[x][-3], x))
last_user = users_dic[users_id_sorted[0]]
for user in users_id_sorted:
    if users_dic[user][-1] == 0:  # 没有题目通过编译，不输出信息
        continue
    else:
        curr_user = users_dic[user]
        # 总分相等，排名和上一位用户排名相同
        if curr_user[0] == last_user[0]:
            curr_user[-2] = last_user[-2]
        else:
            curr_user[-2] = pat_rank
        print("{} {:0>5} {}".format(curr_user[-2], user, curr_user[0]), end='')
        for p_score in curr_user[1:K + 1]:
            if p_score == -1:
                print(" -", end='')
            else:
                print(" " + str(p_score), end='')
        print()
        last_user = curr_user
        pat_rank += 1
