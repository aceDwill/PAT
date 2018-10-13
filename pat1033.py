"""
 solution: divided into two cases
            1.within the max distance, current gas station's
            unit price of gas is the lowest, fill up the tank,
            then go to the station within the distance which has the lowest unit price
            2.within the max distance, there is a gas station
            whose unit price lower than the current station's,
            refill the gas so that the car can reach the station exactly
"""

# c_max (≤ 100), the maximum capacity of the tank
# d (≤30000), the distance between Hangzhou and the destination city
# d_​avg(≤20), the average distance per unit gas that the car can run
# n (≤ 500), the total number of gas stations
c_max, d, d_avg, n = [float(x) for x in input().split()]
# max distance the car can reach running out of a tank of gas
max_distance = c_max * d_avg

stations = []

# save all stations like stations=[[uni price, distance],...]
for i in range(int(n)):
    station = [float(x) for x in input().split()]
    stations.append(station)

# set the destination as the the last station setting with its unit price 0
stations.append([0.0, d])
# sort stations according to their distances
stations.sort(key=lambda x: x[1])

# total cost of the gas
cost = 0.0

if stations[0][1] != 0:
    print("The maximum travel distance = 0.00")
else:
    current_station = 0
    left_gas = 0.0  # the gas left
    while current_station < n:
        next_station = -1
        lowest_price = 1000000
        i = current_station + 1
        while i <= n and (stations[i][1]
                          - stations[current_station][1]) <= max_distance:
            if stations[i][0] < lowest_price:
                next_station = i
                lowest_price = stations[i][0]

            if stations[i][0] < stations[current_station][0]:
                break

            i += 1

        # the car can't reach the next gas station
        if next_station == -1:
            print("The maximum travel distance = {:.2f}"
                  .format(stations[current_station][1] + max_distance))
            break
        else:
            # the gas needed to get to the next station
            gas_needed = (stations[next_station][1]
                          - stations[current_station][1]) / d_avg
            if stations[current_station][0] > stations[next_station][0]:
                cost += (gas_needed - left_gas) * stations[current_station][0]
                # the left gas when get to the next station
                left_gas = 0
            else:
                # fill up the gas tank
                cost += (c_max - left_gas) * stations[current_station][0]
                # the left gas when get to the next station
                left_gas = c_max - gas_needed

            current_station = next_station

    if current_station == n:
        print("{:.2f}".format(cost))
