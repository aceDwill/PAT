"""
    3点运行超时，估计和input输入或者根据字典来存储有关
    思路：1.用地址-node键值对来保存输入
          2.遍历一遍链表，将出现过的元素保存在最终字典里
          3.根据key值大小排序
          4.注意元素为空时，应输出0 -1
"""



class node():
    
    def __init__(self,key,next):
        self.key = key
        self.next = next

N, head_node = input().split()
node_dic = {}
final_node_dic = {}
for i in range(int(N)):
    addr,key,next = input().split()
    mynode = node(key,next)
    node_dic[addr] = mynode

addr = head_node
while addr != "-1":
    final_node_dic[addr] = node_dic[addr]
    addr = node_dic[addr].next

cnt = len(final_node_dic)   #   遍历链表后有多少元素

#   分成元素为空和不为空的情况
if cnt == 0:
    print("0 -1")
else:
    result = sorted(final_node_dic.items(),key=lambda x:x[1].key)
    print(str(cnt) + " " + result[0][0])
    print(result[0][0] + " " + result[0][1].key + " ",end="")

    for node in result[1:]:
        print(node[0])
        print(node[0] + " " + node[1].key + " ",end="")

    print("-1")

