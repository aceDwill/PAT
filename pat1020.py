"""
    思路：1.根据中序和后序找到根节点
          2.根据postion的值决定根节点在列表的位置，左子树的根节点为2*i+1，
            右子树的根节点为2*i+2
          3.将列表按序输出

"""


postorder = []
inorder = []
result = 100000 * ['0']   #   初始化列表，列表要足够大

def level_order(pos, postl, postr, inl, inr):
    if postl > postr:
        return 
    root = postorder[postr]
    r_index = inorder.index(root)     #   在中序序列找到root的索引
    result[pos] = root

    numleft = r_index - inl      #   左子树节点个数
    level_order(2 * pos + 1, postl, postl + numleft - 1, inl, r_index - 1)     #   对左子树层序遍历
    level_order(2 * pos + 2, postl + numleft, postr - 1, r_index + 1, inr)     #   对右子树层序遍历

N = int(input()) - 1
postorder = input().split()
inorder = input().split()

level_order(0, 0, N, 0, N)

print(result[0],end="")
cnt = 0
for x in result[1:]:
    if x != "0":
        cnt += 1
        print(" " + x,end="")
    if cnt == N:
        break



