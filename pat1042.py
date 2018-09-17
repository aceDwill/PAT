"""
     思路：用两个数组，一个数组存储初始牌序，另一个存储洗牌一次后的牌序，然后迭代
"""

K = int(input())  # 洗牌次数
order = [int(x) for x in input().split()]  # 洗牌顺序

cards = [x for x in range(1, 55)]  # 初始牌序
cards_result = [0] * 54  # 最后牌序
cards_color = ["S", "H", "C", "D", "J"]  # 牌的花色

for i in range(K):
    for j in range(54):
        cards_result[order[j] - 1] = cards[j]  # 输入牌序从1开始，要减一

    for k in range(54):
        cards[k] = cards_result[k]  # 存储洗牌一次后的牌序

# 输出第一个结果
first_card = cards_result[0] - 1
print(cards_color[first_card // 13]
      + str(first_card % 13 + 1), end="")
for card in cards_result[1:]:
    card_num = card - 1
    print(" " + cards_color[card_num // 13] + str(card_num % 13 + 1), end="")
