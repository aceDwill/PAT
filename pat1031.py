'''
    思路：遍历找出满足n1 = n3 = max { k| k <= n2 for all 3 <= n2 <= N } with n1 + n2 + n3 - 2 = N.
'''

s = input()
for x in range(1,len(s)):
    n3 = len(s) - 2 * x
    if x == n3:
        vertical_num = x - 1
        break
    elif x + 1 > n3:
        vertical_num = x - 1
        break

for y in range(vertical_num):
    num_blank = len(s) - 2 * vertical_num - 2
    print(s[y] + num_blank * ' ' + s[-(y + 1)])

print(s[vertical_num:-vertical_num])