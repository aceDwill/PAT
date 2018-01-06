class node():

    def __init__(self, weight,children_list):
        self.weight = weight
        self.children_list = children_list

N,M,S = input().split()
S = int(S)
weights = input().split()
Tree = {}       #   存储节点
for i in range(int(N)):
    newnode = node(0,[])
    newnode.weight = weights[i]
    tree_index = "{:0>2}".format(str(i))    #   将索引改成“00”“01”...样式
    Tree[tree_index] = newnode             #    字典结构为｛索引:node(weight,children_list)｝

for i in range(int(M)):
    children = input().split()
    Tree[children[0]].children_list = children[2:]




def dfs(root,sum,track):
    track = track[:]        #   每递归一次，track列表重新指向一个对象，即指向内存一处地址，
                           #   如果不加，就会造成track始终指向内存一处地址，无法递归使用
    sum += int(Tree[root].weight)
    #   如果权值和大于给定权值或者和等于权值并且存在孩子节点，跳过这个节点
    if sum > S or (sum == S and len(Tree[root].children_list) > 0):
        return
    if root != "00":
        track.append(Tree[root])
    c_list = Tree[root].children_list
    if c_list:      #   如果存在孩子节点
        #   将孩子节点按权值从大到小排序
        c_list =  sorted(c_list,key=lambda x:int(Tree[x].weight),reverse=True)
        for i in c_list:
            dfs(i,sum,track)
    else:
        if sum == S:
            print(Tree["00"].weight, end="")
            for j in track:
                print(" " + j.weight, end="")
            print("")
dfs("00",0,[])

