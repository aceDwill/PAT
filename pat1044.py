"""
    solution: 1.use sum_of_1toj to save sum of diamond 1 to j;
              2.if sum_of_1toj[right] - sum_of_1toj[left] == m ,add string "left-right" to solution
              3.if sum_of_1toj[right] - sum_of_1toj[left] < m, left ++
              4.if sum_of_1toj[right] - sum_of_1toj[left] > m, right ++
    attention：test case 3 Time Limit Exceeded
"""
n, m = [int(x) for x in input().split()]
diamonds = [int(x) for x in input().split()]
sum_of_1toj = []  # sum of Diamond 1 to Diamond j
temp = 0
sum_of_1toj.append(0)
for i in diamonds:
    temp += i
    sum_of_1toj.append(temp)

# the index of number to be addressed
left = 0
right = 1

while sum_of_1toj[right] < m:
    right += 1

has_solution = False  # has solution which Di + ... + Dj = M
solutions = []  # all solutions
min_sum = 1000000000
while right <= n:
    temp_sum = sum_of_1toj[right] - sum_of_1toj[left]
    temp_solution = str(left + 1) + '-' + str(right)
    if temp_sum == m:
        if has_solution:
            solutions.append(temp_solution)
        else:
            solutions.clear()
            solutions.append(temp_solution)
            has_solution = True
        left += 1
        right += 1
    elif temp_sum < m:
        right += 1
    else:
        left += 1
        # has no solution which Di + ... + Dj = M
        if not has_solution:
            # update the min sum of the diamonds
            if temp_sum < min_sum:
                solutions.clear()  # delete the previous solution
                min_sum = temp_sum
                solutions.append(temp_solution)
            elif temp_sum == min_sum:
                solutions.append(temp_solution)

for s in solutions:
    print(s)
