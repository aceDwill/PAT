"""
    思路：1.第三个测试点运行超时
          2.建立一个列表，里面存储注册号码，排名等信息
          3.用sort进行排序
"""


N = int(input())
testees = []

#   记录每个区域的开始和终点索引
left = 0
right = 0
for loc_num in range(N):
    K = int(input())
    right += K
    #   输入该区域的考生信息
    for i in range(K):
        testee = {}
        regist_num, score = input().split()
        testee["regist_num"] = regist_num
        testee["score"] = int(score)
        testee["final_rank"] = 0
        testee["loc_num"] = loc_num + 1
        testee["loc_rank"] = 0
        testees.append(testee)
    
    temp_score = -1     #   记录列表前一个元素分数
    temp_rank = 0      #   记录列表前一个元素排名
    #   score要按降序排列，前面要加“-”，分数相同按注册号码升序排列
    for i,testee in enumerate(sorted(testees[left:right],
                key=lambda testee:(-testee["score"],testee["regist_num"]))):
        if testee["score"] == temp_score:
            testee["loc_rank"] = temp_rank
        else:
            temp_score = testee["score"]
            temp_rank = i + 1
            testee["loc_rank"] = temp_rank

    left += K

temp_score = -1     #   记录列表前一个元素分数
temp_rank = 0      #   记录列表前一个元素排名

print(len(testees))

for i,testee in enumerate(sorted(testees,
             key=lambda testee:(-testee["score"],testee["regist_num"]))):
    if testee["score"] == temp_score:
        testee["final_rank"] = temp_rank
    else:
        temp_score = testee["score"]
        temp_rank = i + 1
        testee["final_rank"] = temp_rank
    print(testee["regist_num"] + " " + str(testee["final_rank"])
          + " " + str(testee["loc_num"]) + " " + str(testee["loc_rank"]))

