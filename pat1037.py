nc = int(input())
coupons = [int(x) for x in input().split()]
np = int(input())
products = [int(x) for x in input().split()]

max_money = 0
coupons.sort(reverse=True)
products.sort(reverse=True)

c_p_num = 0  # the number of coupons with positive values
p_p_num = 0  # the number of coupons with positive values
for c in coupons:
    if c > 0:
        c_p_num += 1
    else:
        break
for p in products:
    if p > 0:
        p_p_num += 1
    else:
        break

# min numbers of positive and negative
positive_num = min(c_p_num, p_p_num)
negative_num = min(nc - c_p_num, np - p_p_num)

for i in range(positive_num):
    max_money += coupons[i] * products[i]

for i in range(negative_num):
    max_money += coupons[-i - 1] * products[-i - 1]

print(max_money)
