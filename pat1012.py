"""
    思路：1.用student结构体保存学生信息
          2.对各项成绩c,m,e,a进行排序，将名次存入各个学生中
          3.对每个学生自身的各项成绩排序，输出最好成绩

"""


class student():

    def __init__(self, c, m, e):
        self.c = c
        self.m = m
        self.e = e
        self.a = c + m + e
        self.c_rank = 0
        self.m_rank = 0
        self.e_rank = 0
        self.a_rank = 0

students = {}
#   将a,c,m,e和1，2，3，4对应，便于后面进行名次相同按a,c,m,e课程排序
courses = {1:'A', 2:'C', 3:'M', 4:'E'}
N,M = input().split()

#   输入学号，输出最好排名
def print_rank(id):
    if id not in students.keys():
        print("N/A")
    else:
        s = students[id] 
        rank_dic = {1:s.a_rank, 2:s.c_rank, 3:s.m_rank, 4:s.e_rank}
        #   对学生自身各项成绩按要求进行排序
        result = sorted(rank_dic.keys(), key=lambda x: (rank_dic[x],x))    
        print(str(rank_dic[result[0]]) +" " + courses[result[0]])



for i in range(int(N)):
    stu_info = input().split()
    students[stu_info[0]] = student(int(stu_info[1]),int(stu_info[2]),int(stu_info[3]))

#   对c,m,e,a各项分别进行排序
crank_list = sorted(students.keys(), key=lambda x: students[x].c, reverse=True)
mrank_list = sorted(students.keys(), key=lambda x: students[x].m, reverse=True)
erank_list = sorted(students.keys(), key=lambda x: students[x].e, reverse=True)
arank_list = sorted(students.keys(), key=lambda x: students[x].a, reverse=True)


#   将具体排名存入各个学生中
for rank in range(int(N)):
    id1 = crank_list[rank]
    students[id1].c_rank = rank + 1
    if rank > 0:
        id2 = crank_list[rank - 1]
        if students[id1].c == students[id2].c:
            students[id1].c_rank = students[id2].c_rank
for rank in range(int(N)):
    id1 = mrank_list[rank]
    students[id1].m_rank = rank + 1
    if rank > 0:
        id2 = mrank_list[rank - 1]
        if students[id1].m == students[id2].m:
            students[id1].m_rank = students[id2].m_rank
for rank in range(int(N)):
    id1 = erank_list[rank]
    students[id1].e_rank = rank + 1
    if rank > 0:
        id2 = erank_list[rank - 1]
        if students[id1].e == students[id2].e:
            students[id1].e_rank = students[id2].e_rank
for rank in range(int(N)):
    id1 = arank_list[rank]
    students[id1].a_rank = rank + 1
    if rank > 0:
        id2 = arank_list[rank - 1]
        if students[id1].a == students[id2].a:
            students[id1].a_rank = students[id2].a_rank

for i in range(int(M)):
    id = input()
    print_rank(id)
