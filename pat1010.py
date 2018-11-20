"""
    Solution: 1.use num_dic to convert char to number
              2.convert the chosen number to decimal ,assign it temp
              3.assign (the max number of all digits) + 1 to left,
                assign max(temp,left)+1 to right,
              4.use binary search to find the radix
    attention: 1.the max radix is not 36, radix >= 2
               2.input: 9 9 1 7 ,this test case should output "Impossible",
                 not 10
"""
# convert char to number
num_dic = {}
for i in range(10):
    num_dic[str(i)] = i
for i in range(10, 36):
    num_dic[chr(i + 87)] = i


def convert10(n, radix):
    """convert num to decimal"""
    answer = 0
    for c in n:
        # num >= radix, can't convert to decimal
        if num_dic[c] >= radix:
            return -1
        else:
            answer = answer * radix + num_dic[c]
    return answer


def binary_search(n1, left, right, n2):
    """find the radix using binary search"""
    """n1 is the number to be addressed,n2 has converted to decimal"""
    while left <= right:
        mid = (left + right) // 2
        num1 = convert10(n1, mid)
        if num1 == n2:
            return mid
        elif num1 < n2:
            left = mid + 1
        else:
            right = mid - 1

    return -1  # not found


def find_max_num(n):
    """find the max num of all digits"""
    max_num = -1
    for c in n:
        if num_dic[c] > -1:
            max_num = num_dic[c]
    return max_num


test_case = input().split()
tag = int(test_case[2])
radix = int(test_case[3])

if tag == 1:
    temp = convert10(test_case[0], radix)
    n = test_case[1]
else:
    temp = convert10(test_case[1], radix)
    n = test_case[0]
if temp == -1:
    result = -1
else:
    left = find_max_num(n) + 1
    left = max(left, 2)  # the num of left must >= 2
    right = max(temp + 1, left)
    result = binary_search(n, left, right, temp)
if result == -1:
    print("Impossible")
else:
    print(result)
