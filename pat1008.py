my_list = [int(x) for x in input().split(' ')][1:]
sum_time = 0
now = 0
for x in my_list:
    if x >= now:
        sum_time += 6 * (x - now)
    else:
        sum_time += 4 * (now - x)
    now = x
    sum_time += 5

print(sum_time)
