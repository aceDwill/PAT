""""
    思路：1.创建一个类Record记录每条数据
          2.用一个字典记录输入数据，结构如：records["aaa"] = Record("month:dd:hh:mm",state)
          3.对字典按用户首字母排序进行排序，多条记录按时间顺序排序
          4.计算配对记录所用时间及话费
    注：用户没有配对记录不输出任何信息
"""


class Record:

    def __init__(self, time_info, state):
        self.month, self.day, self.hour, self.min = [
            int(x) for x in time_info.split(':')]
        self.state = state


toll = [int(x) for x in input().split()]  # 各时段费用


#   计算一次通话时间及所需费用,参数为开始时的天，时，分，结束时的天，时，分
def phonebills(ld, lh, lm, cd, ch, cm):
    amount = 0
    phone_minutes = (cd * 24 * 60 + ch * 60 + cm) - (ld * 24 * 60 + lh * 60 + lm)
    while ld < cd or lh < ch or lm < cm:
        amount += toll[lh]
        lm += 1
        if lm == 60:
            lh += 1
            lm = 0
        if lh == 24:
            ld += 1
            lh = 0
    return amount, phone_minutes


N = int(input())

records = {}
for i in range(N):
    curr_record = input().split()
    if curr_record[0] in records.keys():
        records[curr_record[0]].append(Record(curr_record[1], curr_record[2]))
    else:
        records[curr_record[0]] = []
        records[curr_record[0]].append(Record(curr_record[1], curr_record[2]))

#   按姓名字母表排序
for name in sorted(records):
    need_print = True              # 用户存在通话记录需要打印，没有通话时长的不需要打印
    personal_records = records[name]
    #   按时间先后对电话记录排序
    personal_records.sort(key=lambda x: (x.month, x.day, x.hour, x.min))
    total_amount = 0
    is_online = False
    for p_record in personal_records:
        if p_record.state == "on-line":
            is_online = True
            #   记录开始打电话时间
            last_day = p_record.day
            last_hour = p_record.hour
            last_min = p_record.min
        else:
            #   配对成功
            if is_online:
                if need_print:
                    print(name + " " + "{:0>2}".format(personal_records[0].month))
                amount, phone_min = phonebills(
                    last_day, last_hour, last_min, p_record.day, p_record.hour, p_record.min)

                print("{:0>2}:{:0>2}:{:0>2} {:0>2}:{:0>2}:{:0>2} ".format(
                    last_day, last_hour, last_min, p_record.day, p_record.hour, p_record.min), end='')
                print(str(phone_min) + " $" + "{:.2f}".format(amount / 100))
                total_amount += amount
                is_online = False
                need_print = False
    if total_amount != 0:
        print("Total amount: $" + "{:.2f}".format(total_amount / 100))
