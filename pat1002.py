'''   思路: 用字典来处理输入数据
      注：1.测试点1未通过
          2.系数为0的项不算输出里面的项
'''
a = {}
b = {}
my_input = input().strip().split()
#  字典保存输入，使用float处理value
for x in range(int(my_input[0])):
    a[my_input[2 * x + 1]] = float(my_input[2 * x + 2])

my_input = input().strip().split()
for x in range(int(my_input[0])):
    b[my_input[2 * x + 1]] = float(my_input[2 * x + 2])

for key,value in a.items():
    if key in b.keys():

        b[key] = a[key] + b[key]
    else:
        b[key] = a[key]
    if b[key] == 0:
        del b[key]


print(str(len(b)),end='')
# 按项数从大到小输出
for key in sorted(b,reverse=True):
    print(' ' + key + ' ' + '{:.1f}'.format(b[key]),end='')

