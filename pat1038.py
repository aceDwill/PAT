"""
        solution: 1.repeat every string until the length is 8
                  2.save original string and repeated string in a dic
                  3.sort the dic according to its value
                  4.join the strings of keys as the final result
"""

segments = input().split()[1:]
segments_dic = {}
for s in segments:
    segments_dic[s] = (s * 8)[:8]

result = ""
for key in sorted(segments_dic.keys(), key=lambda x: segments_dic[x]):
    result += key

print(int(result))
