"""
    思路：按月饼单价从高到低依次卖月饼，数量不够市场数量的卖下一种，直到满足市场数量
"""


class MoonCake:

    def __init__(self, amount, price, unit_price):
        self.amount = amount
        self.price = price
        self.unit_price = unit_price    # 月饼单价


my_input = input().split()
N = int(my_input[0])
D = float(my_input[1])
amounts = [float(x) for x in input().split()]
prices = [float(x) for x in input().split()]
mooncakes = []

for i in range(N):
    mooncakes.append(MoonCake(amounts[i], prices[i], prices[i] / amounts[i]))
# 按月饼单价排序，从大到小
mooncakes.sort(key=lambda x: (-x.unit_price))
profit = 0
for mc in mooncakes:
    if mc.amount < D:
        profit += mc.price
        D -= mc.amount
    else:
        profit += D * mc.unit_price
        break

print("{:.2f}".format(profit))
