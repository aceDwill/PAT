"""
        solution: 1.create an array to save the index of number
                 2.if 0 is not at the index of 0,swap 0 and the number whose value equals the
                   index of 0
                 3.if 0 is at the index of 0,find out the first number not at the right index,
                   swap them
       attention: 1.test cases 1 Time Limit Exceeded sometimes
                  2.the sample input is like this
                    10
                    3 5 7 2 6 4 9 0 8 1
                    but the test cases is actually like this
                    10 3 5 7 2 6 4 9 0 8 1

"""
seq = [int(x) for x in input().split()]
n = seq[0]
seq = seq[1:]

index_num = {}
# the numbers of number which is not at the right index except 0
left_num = n - 1
num_swaps = 0  # the number of swaps

# save the numbers' index
for i in range(n):
    index_num[seq[i]] = i

    if seq[i] == i and i != 0:
        left_num -= 1

# the first number not in the right index when value 0 at index 0
k = 1
while left_num > 0:

    index_0 = index_num[0]

    if index_0 != 0:
        index_swap = index_num[index_num[0]]
        left_num -= 1
        # update index of 0
        index_num[0] = index_swap
    else:
        while k < n:
            if seq[k] != k:
                index_swap = k
                # update the indexes of 0 and seq[k]
                index_num[0] = k
                index_num[seq[k]] = 0
                break
            k += 1

    # swap the two numbers
    seq[index_0], seq[index_swap] = \
        seq[index_swap], seq[index_0]
    num_swaps += 1

print(num_swaps)
