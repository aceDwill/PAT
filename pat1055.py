"""
    思路：先按规则总体排序，再按具体查询输出具体信息
    注：1，2测试点运行超时
"""


class Rich:

    def __init__(self, name, age, worth):
        self.name = name
        self.age = int(age)
        self.worth = int(worth)


def search_rich(number, amin, amax):
    current_rich = []  # 记录要排序的富豪
    for rich in rich_man_list100:
        if amin <= rich.age <= amax:
            current_rich.append(rich)
    if len(current_rich) == 0:
        print("None")
    else:
        for rich_man in current_rich[:number]:
            print(rich_man.name + " "
                  + str(rich_man.age) + " " + str(rich_man.worth))


N, k = [int(x) for x in input().split()]
rich_man_list = []  # 记录所有富豪的列表
rich_man_list100 = []
age_rich_num = [0] * 200
for i in range(N):
    rich_info = input().split()
    rich_man = Rich(rich_info[0], rich_info[1], rich_info[2])
    rich_man_list.append(rich_man)

rich_man_list.sort(key=lambda x: (-x.worth, x.age, x.name))

for rich in rich_man_list:
    if age_rich_num[rich.age] < 100:
        rich_man_list100.append(rich)
        age_rich_num[rich.age] += 1

for i in range(k):
    number, amin, amax = [int(x) for x in input().split()]
    print("Case #" + str(i + 1) + ":")
    search_rich(number, amin, amax)
