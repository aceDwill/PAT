"""
    思路：1.用字典存储输入数据，如{"01":["02"],...}表示01节点有一个孩子节点02
          2.在深度遍历记下每代节点的叶节点数，并求出最大高度
          3.依次输出每代节点的叶节点数

"""


N,M = [int(x) for x in input().split()]
tree = {}
generation_pop = [0] * N    #   初始每代人的数量为0
max_depth = 0              #    最大高度初始为零
def dfs(root, depth):
    global max_depth
    if root not in tree.keys():     #   如果节点不在tree字典中表示没有孩子节点，列表对应数据+1
        generation_pop[depth] += 1
        max_depth = max(depth, max_depth)   #   更新最大高度
    else:
        for child in tree[root]:
            dfs(child, depth + 1)

for i in range(M):
    children = input().split()
    tree[children[0]] = children[2:]

dfs("01",0)
print(generation_pop[0], end='')
for num in generation_pop[1:max_depth+1]:
    print(" " + str(num), end='')