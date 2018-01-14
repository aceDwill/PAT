"""
    思路：1.用二维列表存储节点数据，如[[1,2,3],[],[]],列表为空代表没有孩子节点
          2.用字典存储某叶节点出售商品数量
          3.用深度优先遍历遍历整棵树

          注：python输入函数太耗时了，导致2，3，5，6测试点运行超时

"""



origin = input().split()
N = int(origin[0])
price = float(origin[1])
rate = float(origin[2])
tree = []
amount_dic = {}         #   记录零售商出售商品数量的字典
for i in range(N):
    children_input = [int(x) for x in input().split()]
    if children_input[0] != 0:
        tree.append(children_input[1:])
    else:
        tree.append([])
        amount_dic[i] = children_input[1]

total_sales = 0.0
def dfs(root, depth):
    global total_sales      #   没有这句话会导致编译错误
    if len(tree[root]) == 0:
        total_sales += (price * 
                        (1 + rate * 0.01) ** depth * amount_dic[root])
    else:
        for child in tree[root]:
            dfs(child,depth + 1)
    



dfs(0,0)
print("{:.1f}".format(total_sales))

