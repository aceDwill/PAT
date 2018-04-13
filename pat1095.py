"""
    思路：1.用一个类Record存储输入数据，将时间转化为秒
          2.先把同一车牌号的记录按时间排序，配对成功的加入valid_records
          3.再将valid_records按时间排序
          4.对每一次查询如果排序好的记录时间小于等于查询时间，状态为in的
            停车数加1，out的停车数减1
          5.在2的步骤上同时累加停车时间，最后按停车时间对其排序后
            输出最长停车时间的车牌号
    注：测试点4运行超时
"""


class Record:

    def __init__(self, plate_number, time, status):
        self.plate_number = plate_number
        self.time = time
        self.status = status


N, K = [int(x) for x in input().split()]
records = []  # 存入所有停车记录
for i in range(N):
    record = input().split()
    pk_hour, pk_min, pk_sec = [int(x) for x in record[1].split(":")]
    pk_time = pk_hour * 3600 + pk_min * 60 + pk_sec  # 转化为秒，方便比较
    current_record = Record(record[0], pk_time, record[2])
    records.append(current_record)

# 先按车牌号排序，再按时间排序
records.sort(key=lambda x: (x.plate_number, x.time))
valid_records = []  # 存储有效记录
last_record = records[0]
park_time = {}  # 储存停车时间，如：{plate_number:time,}
for r in records[1:]:
    # 前一个车牌号和此时的车牌号一样且前一个状态为in，这一个为out则配对成功
    if last_record.plate_number == r.plate_number \
            and last_record.status == "in" and r.status == "out":
        valid_records.append(last_record)
        valid_records.append(r)
        # 计算停车时间
        if r.plate_number in park_time.keys():
            park_time[r.plate_number] += r.time - last_record.time
        else:
            park_time[r.plate_number] = r.time - last_record.time
    last_record = r

valid_records.sort(key=lambda x: x.time)
numCar = 0
record_index = 0
for i in range(K):
    query_time = [int(x) for x in input().split(":")]
    query_time_to_sec = \
        query_time[0] * 3600 + query_time[1] * 60 + query_time[2]
    while record_index < len(valid_records):
        if valid_records[record_index].time <= query_time_to_sec:
            if valid_records[record_index].status == "in":
                numCar += 1
            else:
                numCar -= 1
        else:
            break
        record_index += 1
    print(numCar)

# 对停车时间排序，时间相同按车牌号字母表顺序排序
sort_plate_number = sorted(park_time, key=lambda x: (-park_time[x], x))
print(sort_plate_number[0], end='')
for num in sort_plate_number[1:]:
    if park_time[num] == park_time[sort_plate_number[0]]:
        print(" " + num, end='')
    else:
        break
# 获取最长停车时间
result_time = park_time[sort_plate_number[0]]
# 秒数转化为时分秒制
r_hour = result_time // 3600
result_time = result_time % 3600
r_min = result_time // 60
r_sec = result_time % 60
print(" {:0>2}:{:0>2}:{:0>2}".format(r_hour, r_min, r_sec))
