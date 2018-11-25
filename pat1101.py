"""
    attention: test case 1 Time Limit Exceeded
"""

n = int(input())
nums = [int(x) for x in input().split()]
nums_sorted = sorted(nums)
pivot_candidates = []
max_num = 0
for i in range(n):
    if nums[i] == nums_sorted[i] and nums[i] > max_num:
        pivot_candidates.append(nums[i])
    if nums[i] > max_num:
        max_num = nums[i]

print(len(pivot_candidates))
if pivot_candidates:
    print(pivot_candidates[0], end='')
    for v in pivot_candidates[1:]:
        print(" " + str(v), end='')
else:
    print()
