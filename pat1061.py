s1 = input()
s2 = input()
s3 = input()
s4 = input()
search_string = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ'
book = {'A':'MON','B':'TUE','C':'WED','D':'THU','E':'FRI','F':'SAT','G':'SUN'}
isDay = True    # 找到星期几的标志
for i in range(len(s1)):
    if s1[i] == s2[i]:
        if isDay and s1[i] in book.keys():
            print(book[s1[i]] + ' ',end='')
            isDay = False
            continue
        if  (not isDay) and s1[i] in search_string[:24]:
            hour = search_string.index(s1[i])
            if hour < 10:
                print('0' + str(hour) + ':',end='')
            else:
                print(str(hour) + ':',end='')
            break

for i in range(len(s3)):
    if s3[i] == s4[i] and s3[i] in search_string[10:].lower() + search_string[10:]:
        if i < 10:
            print('0' + str(i))
        else:
            print(i)
        break