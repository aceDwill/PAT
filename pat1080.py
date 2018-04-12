"""
    思路：1.用二维列表存储输入数据，如[[gE,gI,choice1,choice2,...,ID],]
          2.对所有学生成绩按规则排序
          3.排在前面的学生优先按其选择志愿录取
    注：测试点4运行超时

"""

N, M, K = [int(x) for x in input().split()]
quota = [int(x) for x in input().split()]
stu_info = []  # 所有学生信息
admission_result = {}  # 存储最后录取结果
for i in range(M):
    admission_result[i] = []

for i in range(N):
    stu = [int(x) for x in input().split()]
    stu.append(i)  # 表示该同学的id
    stu_info.append(stu)

sort_stu = sorted(stu_info, key=lambda x: (-(x[0] + x[1]), -x[0]))
for stu in sort_stu:
    for choice in stu[2:K + 2]:
        if quota[choice] > 0:  # 名额还有剩
            admission_result[choice].append(stu[-1])
            quota[choice] -= 1  # 名额数减一
            break
        elif quota[choice] == 0:
            last_stu = stu_info[admission_result[choice][-1]]  # 录取的最后一名学生
            if (stu[0] + stu[1]) == (last_stu[0] + last_stu[1]) \
                    and stu[0] == last_stu[0]:  # 所有成绩相同，破格录取
                admission_result[choice].append(stu[-1])
                break
for result in admission_result.values():
    if len(result) == 0:
        print()
    else:
        result.sort()   # 对录取同学按id排序
        print(result[0], end='')
        for stu_id in result[1:]:
            print(" " + str(stu_id), end='')
        print()
