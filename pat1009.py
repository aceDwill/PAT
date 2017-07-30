'''
    思路：1.先用字典将输入存起来，结构类似于{1:1.1,2:2.2,...}
          2.遍历两个字典，将乘积结果存到第三个字典里
          3.去掉系数为0的项，保存在第四个字典里
'''


input_list1 = input().split(' ')
input_list2 = input().split(' ')
poly1 = {}
poly2 = {}
poly3 = {}
poly4 = {}
for x in range(int(input_list1[0])):
    poly1[int(input_list1[2 * x + 1])] = float(input_list1[2 * x + 2])

for x in range(int(input_list2[0])):
    poly2[int(input_list2[2 * x + 1])] = float(input_list2[2 * x + 2])

for key1,value1 in poly1.items():
    for key2,value2 in poly2.items():
        new_key = key1 + key2
        if new_key in poly3.keys():
            poly3[new_key] += value1 * value2
        else:
            poly3[new_key] = value1 * value2

for k,v in poly3.items():
    if v != 0:
        poly4[k] = v

print(len(poly4), end='')
for key in sorted(poly4, reverse=True):
    print(' ' + str(key) + ' ' + '{:.1f}'.format(poly4[key]), end='')
