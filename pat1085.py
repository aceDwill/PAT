# attention: test case 4 Time Limit Exceeded


n, p = [int(x) for x in input().split()]
seq = [int(x) for x in input().split()]
seq.sort()
# the maximum number of integers
# that can be chosen to form a perfect subsequence
max_num = 0
temp = 0

for i in range(n):
    for j in range(i + max_num, n):
        if seq[j] <= seq[i] * p:
            temp = j - i + 1
            max_num = max(max_num, temp)
        else:
            break

print(max_num)
