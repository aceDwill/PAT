"""
    思路：用二维数组存放记录，如[[000007, James, 85]...]，排序后输出
    注：测试点6运行超时，有可能是输入数据过多导致

"""

N, C = [int(x) for x in input().split()]

records = []  # 存储所有记录

for i in range(N):
    record = input().split()
    records.append(record)

for rec in sorted(records, key=lambda x: (x[C - 1], x[0])):
    print(rec[0] + " " + rec[1] + " " + rec[2])
