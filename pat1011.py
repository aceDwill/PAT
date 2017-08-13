game_result = ['W','T','L']
result = 1
for x in range(3):
    game_odds = input().split()
    max_odds = max(game_odds)       #   每场比赛结果最大概率
    result *= float(max_odds)
    print(game_result[game_odds.index(max_odds)] + ' ',end='')      #   查找最大概率的索引，输出对应字符

result = (result * 0.65 - 1) * 2
print('{:.2f}'.format(result),end='')
