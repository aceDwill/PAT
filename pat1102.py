"""
    思路：1.先找到根节点，再通过根节点建立二叉树
          2.通过反转层序遍历和反转中序遍历输出结果
"""

class node():
    
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

N = int(input())
node_dic = {}           #   记录节点之间的对应关系
nodes = [0] * N         #   用于判断节点有没有出现
level = []              #   用于层序遍历的队列
inorder_result = []      #   用于记录中序反转序列结果

#   建立二叉树
def create_BTree(root):
    children = node_dic[root.value]
    if children[0] == '-' and children[1] == '-':
        return 
    if children[0] != '-':
        root.left = node(children[0])
        create_BTree(root.left)
    if children[1] != '-':
        root.right = node(children[1])
        create_BTree(root.right)

#   反转层序遍历
def invert_level_order(root):
    level.append(root)
    print(root.value, end='')
    while len(level) != 0:
        pop_node = level.pop(0)
        if pop_node.right is not None:
            level.append(pop_node.right)
            print(" " + pop_node.right.value, end='')
        if pop_node.left is not None:
            level.append(pop_node.left)
            print(" " + pop_node.left.value, end='')

#   反转中序遍历
def inorder_invert(root):
    if root is None:
        return
    else:
        inorder_invert(root.right)
        inorder_result.append(root.value)
        inorder_invert(root.left)


for x in range(N):
    child_list = input().split()
    #   记录出现过的节点
    for child in child_list:
        if child != '-':
            nodes[int(child)] += 1
    node_dic[str(x)] = child_list

#   没出现过的节点即为根节点
for i,v in enumerate(nodes):
    if v == 0:
        break
root = node(str(i))
create_BTree(root)
invert_level_order(root)
inorder_invert(root)
print()
print(inorder_result[0], end='')
for x in inorder_result[1:]:
    print(" " + x, end='')





