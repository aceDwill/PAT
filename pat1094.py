"""
    思路：1.用字典存储父子节点之间的对应关系，如{"01":["03","02","04","05"],...}
          2.用一个字典存储节点与代数之间的关系，如{"01":1,"03":2,"04":2,..,}
          3.再用一个列表存储每代人的人数
          4.用bfs遍历一遍该树，在遍历过程中修改2，3点中数据
          5.对存储人数列表进行迭代，求出最多人数的代数号

"""



N,M = [int(x) for x in input().split()]
family = {}
for i in range(M):
    family_member = input().split()
    family[family_member[0]] = family_member[2:]


queue = []
generation_pop = [0] * (N + 1)        #   每代人的人数初始为零
generation_ref = {}
def bfs(root):
    queue.append(root)
    generation_pop[1] = 1
    generation_ref[root] = 1        #   “01”为第一代
    while len(queue) != 0:
        now = queue.pop(0)
        if now in family.keys():
            for member in family[now]:
                generation_ref[member] = generation_ref[now] + 1
                queue.append(member)
                generation_pop[generation_ref[member]] += 1    


bfs("01")
max_pop = 0
max_pop_generation = 0
for i,v in enumerate(generation_pop):
    if v > max_pop:
        max_pop = v
        max_pop_generation = i
print(str(max_pop) + " " + str(max_pop_generation))
