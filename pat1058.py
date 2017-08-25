A,B = input().split()

g1,s1,k1 = (int(x) for x in A.split('.'))
g2,s2,k2 = (int(x) for x in B.split('.'))
result = [g1 + g2,s1 + s2,k1 + k2]
if result[2] >= 29:
    result[1] += 1
    result[2] -= 29

if result[1] >= 17:
    result[0] += 1
    result[1] -= 17

result = [str(x) for x in result]   #   将数组每个元素转化为字符形式
print('.'.join(result))

