"""
    思路：1.先把输入序列从小到大排序，可以得到中序序列
          2.根据完全二叉树的特点，求出左子树节点的个数，从而可以得到根节点的位置
          3.对其进行递归调用，可以得到层序遍历序列

"""


import math

N = int(input())
level_order_list = [0] * N
origin = [int(x) for x in input().split()]
origin.sort()       #   对输入数据进行由小到大排序
def level_order(in_order_list, postion):

    num = len(in_order_list)    #   节点个数
    if num == 0:
        return
    elif num == 1:
        level_order_list[postion] = in_order_list[0]
        return
    depth = int(math.log2(num) + 1)      #  求出完全二叉树高度
    last_depth_nodes = num - (2 ** (depth - 1) - 1)   #   求出最后一层节点数
    #   如果最后一层节点数小于等于这层最多节点数的一半
    if last_depth_nodes <= 2 ** (depth - 2):
        left_num_nodes = num - 2 ** (depth - 2)   #   左子树节点个数
    else:
        left_num_nodes = 2 ** (depth - 1) - 1

    level_order_list[postion] = in_order_list[left_num_nodes]  #   根节点为origin全部左子树节点的后一个元素
    level_order(in_order_list[:left_num_nodes], 2 * postion + 1)
    level_order(in_order_list[left_num_nodes + 1:], 2 * postion + 2)

level_order(origin,0)

print(level_order_list[0], end='')
for v in level_order_list[1:]:
    print(" " + str(v), end = '')


