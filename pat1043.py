"""
     思路: 1.将输入数字按二叉排序树过程建树    
		  2.通过将先序遍历或先序镜像遍历得到序列与输出序列比较，看是否一致
		  3.若一致，则输出后序遍历序列或后序镜像遍历序列，不一致输出NO

          注：测试点5未通过

"""



pre_list = []                   #   先序遍历后序列
pre_mirror_list = []            #   先序镜像遍历后序列
post_list = []                  #   后序遍历后序列
post_mirror_list = []           #   后序镜像遍历后序列

class BSTree():

    def __init__(self,data):
        self.data = data
        self.left = None
        self.right = None

    #   BST插入函数  
    def insert(self, x):
        if x < self.data:
            if self.left is None:
                self.left = BSTree(x)
            else:
                self.left.insert(x)
        else:
            if self.right is None:
                self.right = BSTree(x)
            else:
                self.right.insert(x)

    #   先序遍历
    def preOrder(self):
        pre_list.append(self.data)
        if self.left is not None:
            self.left.preOrder()
        if self.right != None:
            self.right.preOrder()

    #   先序镜像遍历
    def preMirrorOrder(self):
        pre_mirror_list.append(self.data)
        if self.right is not None:
            self.right.preMirrorOrder()
        if self.left is not None:
            self.left.preMirrorOrder()

    #   后序遍历
    def postOrder(self):
        if self.left is not None:
            self.left.postOrder()
        if self.right is not None:
            self.right.postOrder()
        post_list.append(self.data)

    #   后序镜像遍历
    def postMirrorOrder(self):
        if self.right is not None:
            self.right.postMirrorOrder()
        if self.left is not None:
            self.left.postMirrorOrder()
        post_mirror_list.append(self.data)


        
n = int(input())
pre = [int(x) for x in input().split()]

root = BSTree(pre[0])
for x in pre[1:]:
    root.insert(x)

root.preOrder()
root.preMirrorOrder()

if pre_list == pre:
    print("YES")
    root.postOrder()
    print(post_list[0],end="")
    for x in post_list[1:]:
        print(" " + str(x), end="")
elif pre_mirror_list == pre:
    print("YES")
    root.postMirrorOrder()
    print(post_mirror_list[0],end="")
    for x in post_mirror_list[1:]:
        print(" " + str(x), end="")
else:
    print("NO")







