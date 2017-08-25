'''
    思路：1.将所有距离加起来，和为sum
          2.将1号点到第i个点的下一个点的距离存储到distance[i]
          3.计算两个点之间的距离，即distance[b - 1] - distance[a - 1]
          4.比较sum和3中距离，输出最小结果
          

		 PS：1.如果数组距离进行处理，每次迭代计算a到b的距离，测试点2会出现运行超时
              2.python在注意第一点的情况下还是会超时
'''

temp = [int(x) for x in input().split()][1:]    #   获取距离列表
sum = 0
distence = [0]  #   distence[0]应初始化为0
for x in temp:
    sum += x
    distence.append(sum)

m = int(input())

for x in range(m):
    a,b = ((int(x) - 1) for x in input().split())
    if a > b:
        a,b = b,a
    result = distence[b] - distence[a]
    print(min(result,sum - result))

    

