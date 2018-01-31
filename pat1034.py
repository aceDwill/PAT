"""
    思路：采用DFS对连通分量进行遍历，输出结果
    注：为什么采用hnt_info？
        因为python不像c++有引用类型，故采取字典类型使其在递归过程中保存变量值

    3，4，5测试点因为输入数据耗时问题，不能通过

"""


N,K = [int(x) for x in input().split()]
people = []
weight = [0] * N
G = [[0 for i in range(N)] for j in range(N)]   #   初始一个N*N，值为0的邻接矩阵
visited = [False] * N
Gang = {}
hnt_info = {}       #   存储黑帮首领head，成员数量numMember, 总边权totalValue


def DFS(nowVisit, hnt_info):
    
    hnt_info["numMember"] += 1
    visited[nowVisit] = True
    if weight[nowVisit] > weight[hnt_info["head"]]:
        hnt_info["head"] = nowVisit
    for i in range(len(people)):
        if G[nowVisit][i] > 0:
            hnt_info["totalValue"] += G[nowVisit][i]
            G[nowVisit][i] ,G[i][nowVisit] = 0,0    #   删除这条边，防止回头
            if visited[i] == False:
                DFS(i,hnt_info)

def DFSTravel():
    for i in range(len(people)):
        if visited[i] == False:
            hnt_info["head"] = i
            hnt_info["numMember"] = 0
            hnt_info["totalValue"] = 0
            DFS(i, hnt_info)
            if hnt_info["numMember"] > 2 and hnt_info["totalValue"] > K:
                Gang[people[hnt_info["head"]]] = hnt_info["numMember"]



def nameToId(name):
    if name in people:
        return people.index(name)
    else:
        people.append(name)
        return len(people) - 1


for i in range(N):
    n1,n2,t = input().split()
    t = int(t)
    id1 = nameToId(n1)
    id2 = nameToId(n2)
    weight[id1] += t
    weight[id2] += t
    G[id1][id2] += t
    G[id2][id1] += t


DFSTravel()

print(len(Gang))
# 对结果进行字母表排序
for k in sorted(Gang):
    print(k + " " + str(Gang[k]))
