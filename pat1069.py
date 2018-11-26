n = "{:0>4}".format(input())


def non_increasing_num(i):
    temp = sorted(i, reverse=True)
    return "{:0>4}".format("".join(temp))


def non_decreasing_num(i):
    temp = sorted(i)
    return "{:0>4}".format("".join(temp))


result = int(non_increasing_num(n)) - int(non_decreasing_num(n))
print(non_increasing_num(n)
      + " - " + non_decreasing_num(n) + " = " + "{:0>4}".format(result))

while result != 0 and result != 6174:
    result = "{:0>4}".format(result)
    a = non_increasing_num(result)
    b = non_decreasing_num(result)
    result = int(a) - int(b)
    print(a + " - " + b + " = " + "{:0>4}".format(result))
