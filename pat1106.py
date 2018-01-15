"""
    思路：具体见pat1090
    注：测试点2，3，5，6，7运行超时

"""


origin = input().split()
N = int(origin[0])
price = float(origin[1])
rate = float(origin[2]) / 100

tree = []  
for i in range(N):
    child = [int(x) for x in input().split()]
    tree.append(child[1:])

min_depth = 100000
num = 0
def dfs(root, depth):
    global min_depth, num
    if len(tree[root]) == 0:
        if depth < min_depth:
            min_depth = depth
            num = 1
        elif depth == min_depth:
            num += 1
    else:
        for child in tree[root]:
            dfs(child, depth + 1)

dfs(0,0)
result = price * (1 + rate) ** min_depth
print("{:.4f}".format(result) + " " + str(num))
