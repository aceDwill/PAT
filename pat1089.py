"""
    思路：在归并排序过程中判断是否与排过序的序列相等
          如果存在相等序列则是归并排序，否则为插入排序
"""

n = int(input())
init_seq = [int(x) for x in input().split()]
partially_sorted_seq = [int(x) for x in input().split()]


def insert_sort():
    has_inserted = False
    for i in range(1, n):
        temp = partially_sorted_seq[i]
        j = i
        while j > 0 and temp < partially_sorted_seq[j - 1]:
            partially_sorted_seq[j] = partially_sorted_seq[j - 1]
            j -= 1
            has_inserted = True

        partially_sorted_seq[j] = temp
        # break after a num has inserted
        if has_inserted:
            break


def merge_sort():
    i = 2
    is_merge_sort = False
    while i <= 2 * n:
        j = 0
        if init_seq == partially_sorted_seq and i != 2:
            is_merge_sort = True
        while j < n:
            init_seq[j:min(j + i, n)] = sorted(init_seq[j:min(j + i, n)])
            j += i

        i *= 2
        if is_merge_sort:
            return is_merge_sort


if merge_sort():
    print("Merge Sort")
    print(init_seq[0], end='')
    for v in init_seq[1:]:
        print(' ' + str(v), end='')
else:
    print("Insertion Sort")
    insert_sort()
    print(partially_sorted_seq[0], end='')
    for v in partially_sorted_seq[1:]:
        print(' ' + str(v), end='')
