"""
    思路：1.用一个列表存储数据，如[[name,ID,grade],]
          2.按总成绩对所有学生排序
          3.在要求范围成绩内的学生，输出他的信息
"""


N = int(input())
students = []
for i in range(N):
    stu = input().split()
    stu[2] = int(stu[2])
    students.append(stu)

grade1, grade2 = [int(x) for x in input().split()]
students.sort(key=lambda x: -x[2])
has_stu = False  # 表示没有输出任何学生成绩
for stu in students:
    if grade1 <= stu[2] <= grade2:
        print(stu[0] + " " + stu[1])
        has_stu = True
if not has_stu:
    print("NONE")
