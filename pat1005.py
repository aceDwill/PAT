my_dic = {'0':'zero','1':'one','2':'two','3':'three','4':'four','5':'five','6':'six','7':'seven','8':'eight','9':'nine'}
a = input()
sum = 0
for x in a:
    sum += int(x)
result = str(sum)
cnt = 0
for x in result:
    print(my_dic[x], end='')
    cnt += 1
    if cnt != len(result):
        print(' ', end='')


