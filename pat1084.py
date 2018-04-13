"""
    思路：1.先将输入字符串转化为大写形式
          2.遍历键盘打印的字符串，用一个列表记录出现过的字符
          3.遍历原字符串，如果字符没有出现过就输出，并加入记录列表中
"""


original_string = input().upper()
type_out_string = input().upper()

keys_list = []
for s in type_out_string:
    if s not in keys_list:
        keys_list.append(s)
for s in original_string:
    if s not in keys_list:
        keys_list.append(s)
        print(s, end='')
