"""
    思路：1.通过先序序列和中序序列建立二叉树
          2.输出后序遍历序列

          注：测试点4返回非零
"""


inputorder, preorder = [], []
inorder = []

class node():
    
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right =None


#   建立二叉树
def create_BTree(prel, prer, inl, inr):
    if prel > prer:
        return
    temp_value = preorder[prel]
    root = node(temp_value)
    root_index = inorder.index(temp_value)
    left_num = root_index - inl             #   左子树节点个数
    root.left = create_BTree(prel+1, left_num+prel, inl, root_index-1)  
    root.right = create_BTree(left_num+prel+1, prer, root_index+1, inr)
    return root
    

def post_order(root, post_order_list):
    if root is None:
        return
    post_order(root.left, post_order_list)
    post_order(root.right, post_order_list)
    post_order_list.append(root.value)
        

N = int(input())

#   记录先序遍历序列和中序遍历序列
for i in range(2*N):
    operation = input()
    if operation != "Pop":
        inputorder.append(int(operation[5]))
        preorder.append(int(operation[5]))
    else:
        inorder.append(inputorder.pop())


root = create_BTree(0, N-1, 0, N-1)
post_list = []
post_order(root,post_list)

print(post_list[0], end='')

for x in post_list[1:]:
    print(" " + str(x), end='')






