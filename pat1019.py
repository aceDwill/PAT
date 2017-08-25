'''
    思路：将每位数用列表存起来，注意N=0的情况
'''

N,b = input().split()
N,b = int(N),int(b)
result = []
if N == 0:
    result.append(0)
while N > 0:
    result.append(N % b)
    N = N // b
if result == result[::-1]:
    print('Yes')
else:
    print('No')

for i,s in enumerate(result[::-1]):
    print(s,end='')
    if i != len(result) - 1:
        print(' ',end='')
