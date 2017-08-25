a,b = input().split('E')
if a[0] == '-':
    print('-',end='')
#   分幂小于0和幂大于等于0的情况
if int(b) < 0:
    print('0.' + ((-1 - int(b)) * '0') + a[1] + a[3:])
else:
    if len(a) - 3 <= int(b):    #   幂大于等于小数位数的情况
        print(a[1] + a[3:] + (int(b) - len(a) + 3) * '0')
    else:
        print(a[1] + a[3:(3 + int(b))] + '.' + a[3 + int(b):])  #   幂小于小数位数的情况
