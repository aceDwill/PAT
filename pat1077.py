'''
    测试点2未通过
    思路： 1.先比较两个字符串，找出公共部分，若没有，则输出nai
		  2.在以后每个字符串中找公共字符串，若每个都有则输出公共字符串
		  3.若有一个不包含公共字符串，则输出nai
'''

N = int(input())
sentences = []
for i in range(N):
    sentences.append(input())

sentence1 = sentences[0][::-1]
sentence2 = sentences[1][::-1]

common_cnt = 0  #   相同字符个数
for i in range(len(sentence1)):
    if sentence1[i] != sentence2[i]:
        break
    common_cnt += 1

if common_cnt == 0:
    print('nai')
else:
    common_string = sentences[0][-common_cnt:].strip()
    flag = True
    for i in range(2,N):
        if sentences[i].find(common_string) == -1:
            flag = False
            print('nai')
            break

    if flag == True:
        print(common_string)


