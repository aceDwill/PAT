"""
    思路：就是一般的平衡二叉树建立过程，网上可以搜一下教程

"""



class node():

    def __init__(self,value):
        self.value = value
        self.left = None
        self.right = None
        self.depth = 1
    
def getHight(root):
    if root is None:
        return 0;
    else:
        return root.depth

def updateHight(root):
    root.depth = max(getHight(root.left), getHight(root.right)) + 1

def getBalanceFactor(root):
    return getHight(root.left) - getHight(root.right)


def leftRotate(root):
    temp = root.right
    root.right  =temp.left
    temp.left = root
    updateHight(root)
    updateHight(temp)
    root = temp
    return root

def rightRotate(root):
    temp = root.left
    root.left = temp.right
    temp.right = root
    updateHight(root)
    updateHight(temp)
    root = temp
    return root

def insert(root, value):
    if root is None:
        root = node(value)

    elif value < root.value:
        root.left = insert(root.left, value)
        updateHight(root)
        if getBalanceFactor(root) == 2:
            if getBalanceFactor(root.left) == 1:
                root = rightRotate(root)
            else:
                root.left = leftRotate(root.left)
                root = rightRotate(root)
    elif value > root.value:
        root.right = insert(root.right, value)
        updateHight(root)
        if getBalanceFactor(root) == -2:
            if getBalanceFactor(root.right) == -1:
                root = leftRotate(root)
            else:
                root.right = rightRotate(root.right)
                root = leftRotate(root)

    return root



N = int(input())
origin = [int(x) for x in input().split()]

root = None
for value in origin:
    root = insert(root, value)

print(root.value)