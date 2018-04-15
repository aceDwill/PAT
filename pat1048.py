"""
    注：测试点3运行超时
"""


N, M = [int(x) for x in input().split()]
coins = [int(x) for x in input().split()]

coins.sort()
has_solution = False
all_values = [0] * 1000
for coin_value in coins:
    all_values[coin_value] += 1

for coin_value in coins:
    num = M - coin_value
    if coin_value == num and all_values[num] == 1:
        continue
    if all_values[num] >= 1:
        print(str(coin_value) + " " + str(num))
        has_solution = True
        break

if not has_solution:
    print("No Solution")
