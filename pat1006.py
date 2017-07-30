'''
    思路：1.先用字典把数据存起来，结构为：{'ID_number':['in_hour','in_minute','in_second','out_hour','out_minute','out_second]}
          2.对字典按hour,minute,second进行排序
          3.排序后的列表结构为[('2', ['08', '00', '00']), ('1', ['15', '30', '28']), ('3', ['21', '45', '00'])]
            输出第一个元组的第一个元素即可
'''

m = int(input())
records = {}
for x in range(m):
    ID_number,sign_in_time,sigh_out_time = input().split(' ')
    records[ID_number] = sign_in_time.split(':') + sigh_out_time.split(':')
print(sorted(records.items(),key=lambda x: (x[1][0],x[1][1],x[1][2]))[0][0] + ' ', end='')
print(sorted(records.items(),key=lambda x: (x[1][3],x[1][4],x[1][5]), reverse=True)[0][0], end='')

