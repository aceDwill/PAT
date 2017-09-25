"""
    思路：划分为每四个字符串处理一次

"""



chinese_num = {'1':'yi','2':'er','3':'san',
           '4':'si','5':'wu','6':'liu',
           '7':'qi','8':'ba','9':'jiu',}
chinese_bit = ['Shi','Bai','Qian','Wan','Yi']

N = input()
result = ''
#   除去负号的字符串
if N[0] == '-':
    result += 'Fu'
    N = N[1:]

#   得到首尾索引值
left = 0
right = len(N) - 1

while right > 3:
    right -= 4

flag = False     #   表示没有累积零

while left < len(N):
    isPrint = False     #   表示该节有数输出
    while left <= right:
        if N[left] == '0':
            flag = True
        else:
            if flag == True:
                result += ' ling'
                flag = False
            
            result += ' ' + chinese_num[N[left]]
            if right - left - 1 >= 0: 
                result += ' ' + chinese_bit[right - left - 1]
            isPrint = True

        left += 1

    if isPrint and left != len(N):
        result +=' ' + chinese_bit[(len(N) - right) // 4  + 2]

    right += 4

#   特殊情况0
if N == '0':
    result += 'ling'
print(result.strip())      #   去除首尾的空格,并输出




        


