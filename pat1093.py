"""
    思路：1.遍历输入，记录每个字母左边'P'出现个数
          2.倒序遍历输入，记录'T'个数，并在遇到'A'时计算'P'个数与'T'个数乘积
          3.将遇到所有'A'的情况累加起来，即为所求

"""



leftnumP = [0] * 100010
mod = 1000000007

origin = input()

for i,v in enumerate(origin):
    if i != 0:
        leftnumP[i] = leftnumP[i-1]
    if origin[i] == 'P':
        leftnumP[i] += 1


rightnumT = 0
numPAT = 0
for i in range(len(origin)-1,-1,-1):
    if origin[i] == 'T':
        rightnumT += 1
    elif origin[i] == 'A':
        numPAT = (numPAT + leftnumP[i] * rightnumT) % mod

print(numPAT)

