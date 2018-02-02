"""
    思路：1.先将输入成绩按要求分为sage,nobleman,foolman,smallman,并添加到people中
          2.对四种人分别进行排序，按照s,n,f,s依次输出四种人的成绩
          注：2，3，4测试点运行超时

"""
N,L,H = [int(x) for x in input().split()]
people = []
sages = {}
noblemen = {}
foolmen = {}
smallmen = {}

for i in range(N):
    stu_info = input().split()
    vg = int(stu_info[1])
    tg = int(stu_info[2])
    if vg >= H and tg >= H:
        sages[stu_info[0]] = [vg,tg]
    elif vg >= H and tg >= L:
        noblemen[stu_info[0]] = [vg,tg]
    elif vg >= tg and tg >= L:
        foolmen[stu_info[0]] = [vg,tg]
    elif vg >= L and tg >= L:
        smallmen[stu_info[0]] = [vg,tg]

people.append(sages)
people.append(noblemen)
people.append(foolmen)
people.append(smallmen)
print(len(sages) + len(noblemen) + len(foolmen) + len(smallmen))
for i in range(4):
    for id in sorted(people[i].keys(), key=lambda x:(-(people[i][x][0] + people[i][x][1]), 
                                                     -people[i][x][0], people[i][x])):
        print(id + " " + str(people[i][id][0]) + " " + str(people[i][id][1])) 
