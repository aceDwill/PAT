"""
    思路：运用树的dfs遍历，找出树的最大高度，和具有相同最大高度的路径数
    注：测试点1，2，6返回非零

"""



origin = input().split()
N = int(origin[0])
price = float(origin[1])
rate = float(origin[2]) / 100

nodes = [int(x) for x in input().split()]
tree = []

#   建立一个列表，如[[1,2,3],...]表示0号节点的子树为1，2，3
for i in range(N):
    tree.append([])
for i,v in enumerate(nodes):
    if v == -1:
        root = i
        continue
    tree[v].append(i)

max_depth = 0       #   最大高度
num = 0             #   拥有相同最大高度路径数
def dfs(root, depth):
    global max_depth, num

    if len(tree[root]) == 0:
        if depth > max_depth:
            max_depth = depth
            num = 1      #      刷新相同最大高度的路径数  
        elif depth == max_depth:
            num += 1
    else:
        for child in tree[root]:
            dfs(child, depth + 1)

dfs(root, 0)
print("{:.2f}".format(price * (1 + rate) ** max_depth) 
      + " " + str(num))

