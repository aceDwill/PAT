''' 思路：1.将a+b结果处理为字符串
          2.字符串反转后，按3位分割字符串
          3.用‘，’连接分割后的字符串

          注：为什么分割前要反转？因为结果长度不定，
              反转后，可以使输出结果前面位数在3位以内
'''

#  按间距为3分割字符串
def my_split(str, width):
    return [str[x:x+width] for x in range(0,len(str),width)]

#  将输入转换为数字
a,b = (int(x) for x in input().strip().split())
c = a + b
sign = ''

#  如果结果为负，转换为整数，并在输出结果前面加‘-’
if c < 0:
    c = -c 
    sign += '-'

c = str(c)[::-1]
c = ','.join(my_split(c,3))    #  分割后用‘，’连接
print(sign + c[::-1])



