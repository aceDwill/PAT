def to13(x):
    x = int(x)
    result = []
    if x == 0:
        return '00'
    while(x > 0):
        result.append('0123456789ABC'[x % 13])
        x //= 13
    if len(result) == 1:
        result.insert(1,'0')
    sresult = ''.join(result[::-1])   #   将结果合并成字符串
    return sresult

r,g,b = (to13(x) for x in input().split())
print('#' + r + g + b)

