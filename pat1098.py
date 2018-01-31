"""
    思路：在插入排序过程中和part_sort列表比较，如果存在相等的情况则是插入排序，否则是堆排序

"""


N = int(input())
origin = [int(x) for x in input().split()]
part_sort = [int(x) for x in input().split()]

#   向下调整堆
def downAdjust(low, high):
    i = low
    j = 2 * i + 1
    while j <= high:
        if j + 1 <= high and origin[j + 1] > origin[j]:
            j = j + 1
        if origin[i] < origin[j]:
            origin[i],origin[j] = origin[j],origin[i]
            i = j
            j = 2 * i + 1
        else:
            break

#   堆排序  
def heapSort(N):
    isExit = False
    index = N // 2 - 1
    while index >= 0:
        downAdjust(index,N - 1)
        index -= 1
    while N >= 1:
        if origin == part_sort:
            isExit = True
        origin[N - 1],origin[0] = origin[0],origin[N - 1]
        downAdjust(0,N - 2)
        if isExit == True:
            print(origin[0],end='')
            for v in origin[1:]:
                print(" " + str(v),end='')
            return
        N -= 1
    


flag = False        #   默认为堆排序
for i in range(2,N + 1):
    temp_sort = sorted(origin[:i]) + origin[i:]
    if temp_sort == part_sort:
        flag = True
        break

if flag:    #   如果是插入排序
    result = sorted(origin[:i + 1]) + origin[i + 1:]
    print("Insertion Sort")
    print(result[0],end='')
    for v in result[1:]:
        print(" " + str(v),end='')
else:
    print("Heap Sort")
    heapSort(N)

