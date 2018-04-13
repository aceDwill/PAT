"""
    思路：1.遍历出现过数字，用一个数组记录数字出现过的次数
          2.第二次遍历数字，当出现次数为1时输出，没有输出None
"""


bet_num = [int(x) for x in input().split()][1:]
appeared_count = [0] * 10010
has_printed = False

for num in bet_num:
    appeared_count[num] += 1

for num in bet_num:
    if appeared_count[num] == 1:
        print(num)
        has_printed = True
        break
if not has_printed:
    print("None")
