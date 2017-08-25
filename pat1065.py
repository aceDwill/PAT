T = int(input())
for x in range(T):
    a,b,c = (int(y) for y in input().split())
    print("Case #" + str(x + 1) + ": " + str(a + b > c).lower())

