/*
	solution: divided into two cases
			    1.within the max distance, current gas station's unit price of gas is 
				 the lowest, fill up the tank, then go to the station within the distance
			     which has the lowest unit price
			    2.within the max distance, there is a gas station whose unit price lower 
				 than the current station's, refill the gas so that the car can reach the
				 station exactly
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct GasStation {

	double unit_price;
	double distance;
};

bool comp(GasStation g1, GasStation g2) {
	return g1.distance < g2.distance;
}

int main() {

	//c_max (¡Ü 100), the maximum capacity of the tank; 
	//D (¡Ü30000), the distance between Hangzhou and the destination city; 
	//d_avg (¡Ü20), the average distance per unit gas that the car can run
	double c_max, D, d_avg;
	int N;		// the total number of gas stations
	cin >> c_max >> D >> d_avg >> N;

	// the max distance the car can reach running out of a tank of gas
	double max_distance = c_max * d_avg;

	vector<GasStation> v;
	GasStation gs;

	for (int i = 0; i < N; i++) {
		cin >> gs.unit_price >> gs.distance;
		v.push_back(gs);
	}

	// set the destination as the last station with setting its unit price 0
	gs.distance = D;
	gs.unit_price = 0;
	v.push_back(gs);

	// sort the stations according to their distances 
	sort(v.begin(), v.end(), comp);

	if (v[0].distance != 0) {
		cout << "The maximum travel distance = 0.00";
	}
	else {
		int current_station = 0;
		double left_gas = 0;
		double cost = 0;
		while (current_station < N) {

			// the index of station which has the lowest unit price 
			int next_station = -1;
			double lowest_price = 10000000;		// the lowest unit price
			for (int i = current_station + 1; i <= N &&
				(v[i].distance - v[current_station].distance) <= max_distance; i++) {
				if (v[i].unit_price < lowest_price) {
					next_station = i;
					lowest_price = v[i].unit_price;
				}

				if (v[i].unit_price < v[current_station].unit_price) {
					break;
				}
			}

			// can't reach the next gas station
			if (next_station == -1) {
				printf("The maximum travel distance = %.2f\n",
					v[current_station].distance + max_distance);
				break;
			}
			else {
				// the gas needed to get to the next station
				double gas_needed = (v[next_station].distance
					- v[current_station].distance) / d_avg;
				// refill exactly the gas to reach the next gas station
				if (v[current_station].unit_price > lowest_price) {
					cost += (gas_needed - left_gas) * v[current_station].unit_price;
					left_gas = 0;
				}
				else {
					// fill up the gas tank
					cost += (c_max - left_gas) * v[current_station].unit_price;
					left_gas = (c_max - gas_needed);
				}
				current_station = next_station;
			}

		}
		if (current_station == N) {
			printf("%.2f", cost);
		}
	}


	return 0;
}