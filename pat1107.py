"""
    思路：并查集的运用，可以网上搜下教程

"""


father = list(range(1010))
isRoot = [0] * 1010
hobby = [-1] * 1010
def findFather(x):
    a = x
    while(x != father[x]):
        x = father[x]
    
    #   路径压缩
    while(a != father[a]):
        z = a
        a = father[a]
        father[z] = x
        
    return x

def union(a, b):
    FAa = findFather(a)
    FAb = findFather(b)

    if FAa != FAb:
        father[FAb] = FAa


N = int(input())
for person in range(N):
    hobbies = [int(x) for x in input().split()[1:]]
    for p_hobby in hobbies:
        if hobby[p_hobby] == -1:
            hobby[p_hobby] = person
        union(findFather(hobby[p_hobby]),person)

for i in range(N):
    isRoot[findFather(i)] += 1

result = []
for v in isRoot:
    if v != 0:
        result.append(v)

result.sort(reverse=True)
print(len(result))
print(result[0],end='')
for v in result[1:]:
    print(" " + str(v),end='')
