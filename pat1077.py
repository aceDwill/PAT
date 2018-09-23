"""
     思路：1.将所有字符串反转，便于后续处理，并求出最短字符串长度
          2.从0索引比较所有反转字符串相同索引各字符是否相等
"""

N = int(input())
sentences = []
minLen = 300  # 所有句子最短长度
for i in range(N):
    sentence = input()[::-1]
    if len(sentence) < minLen:
        minLen = len(sentence)
    sentences.append(sentence)

common_cnt = 0  # 相同字符个数

for i in range(minLen):
    commonC = sentences[0][i]
    hasSuffix = True  # 表示各索引的所有字符相同
    for sentence in sentences:
        if sentence[i] != commonC:
            hasSuffix = False
            break
    if hasSuffix:
        common_cnt += 1
    else:
        break

if common_cnt == 0:
    print("nai")
else:
    print(sentences[0][:common_cnt][::-1])
