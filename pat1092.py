"""
    思路：1.先遍历商店拥有的beads，用一个字典来记录出现过的数量
          2.遍历Eva需要的beads，如果商店没有或数量不够，缺少数+1
          3.如果缺少数为0，输出Yes，否则输出No
"""

shop_beads = input()
Eva_beads = input()
shop_beads_has = {}  # 记录商店每种beads的数量
for color in shop_beads:
    if color not in shop_beads_has.keys():
        shop_beads_has[color] = 1
    else:
        shop_beads_has[color] += 1

beads_missing = 0  # 记录Eva需要但不能满足的beads数量
for color in Eva_beads:
    if color not in shop_beads_has.keys():
        beads_missing += 1
    else:
        shop_beads_has[color] -= 1
        # 商店beads数不能满足需要的情况
        if shop_beads_has[color] < 0:
            beads_missing += 1

if beads_missing == 0:
    print("Yes " + str(len(shop_beads) - len(Eva_beads)))
else:
    print("No" + " " + str(beads_missing))
