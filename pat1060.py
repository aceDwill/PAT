"""
    思路：分别获取数字的有效数字部分和指数，将两者相比，看是否相等
"""

def deal(s,n):
    e = 0   #   记录指数
    sig_dig = s.lstrip("0.")    #   去除前边的0和小数点，找到有效数字部分
    if sig_dig == '':
        e = 0           #   输入为零的情况，指数为零
    elif '.' in sig_dig:
        e = sig_dig.index('.')      #   有小数点存在的情况，指数为小数点索引
        sig_dig = sig_dig[:e] + sig_dig[e + 1:]      #   删除小数点
    else:
        if '.' in s:    
            e = len(s) - len(sig_dig) - s.index('.') - 1    #   小于1的情况，即0.0000234
            e = -e      #   上面e获取的是小数点0的个数，取反则是指数
        else:
            e = len(sig_dig)    #   大于1且没有小数部分，指数为有效数字位数

    N = int(n)
    #   有效数字位数小于N，直接输出，不够添0补足位数
    if N <= len(sig_dig):
        sig_dig = sig_dig[:N]
    else:
        sig_dig += (N - len(sig_dig)) * '0'

    return sig_dig,e

N,A,B = input().split()
A,e1 = deal(A,N)
B,e2 = deal(B,N)
if A == B and e1 == e2:
    print("YES 0." + A + "*10^" + str(e1))
else:
    print("NO 0." + A + "*10^" + str(e1) + " 0." + B + "*10^" + str(e2))





