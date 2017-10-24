"""
    最后一个测试点超时，可能是字典和python输入方法的问题(c++中用cin也会出现超时)
    思路：1.用字典和一个node类存储数据
          2.遍历第一个字符串，将标志改为true
          3.遍历第二个字符串，遇到标志为true的输出其地址，没有遇到则输出-1

"""


class node():
    
    def __init__(self,data,next):
        self.data = data
        self.next = next
        self.flag = False   #   节点初始化，表示都没被访问过


addr1,addr2,N = input().split()

node_dic = {}

for i in range(int(N)):
    address,data,next = input().split()
    onenode = node(data,next)
    node_dic[address] = onenode

address = addr1
while address != '-1':
    node_dic[address].flag = True
    address = node_dic[address].next

address = addr2
while address != '-1':
    if node_dic[address].flag == True:
        print(address)
        break
    address = node_dic[address].next

if address == '-1':
    print("-1")
        


        