"""
    思路：通过中序遍历建立二叉树，再通过层序遍历输出
    注：数据结构如：[[1,6,58],...]表示为0号节点左孩子节点为1，右孩子节点为6，值为58

"""
N = int(input())
tree = []

for i in range(N):
    children = [int(x) for x in input().split()]
    tree.append(children)

origin = [int(x) for x in input().split()]
origin.sort()

index = 0
def inorder(root):
    global index
    if root == -1:
        return
    inorder(tree[root][0])
    tree[root].append(origin[index])
    index += 1
    inorder(tree[root][1])

queue = []
def bfs(root):
    queue.append(root)
    print(tree[root][2],end='')
    while(len(queue) != 0):
        now = queue.pop(0)
        left = tree[now][0]     #   左孩子节点
        right = tree[now][1]    #   右孩子节点   
        if left != -1:
            queue.append(left)
            print(" " + str(tree[left][2]), end='')
        if right != -1:
            queue.append(right)
            print(" " + str(tree[right][2]), end='')

inorder(0)
bfs(0)


