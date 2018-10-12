/*
        solution: divided into two cases
                  1.within the max distance, current gas station's unit price of gas is
                    the lowest, fill up the tank, then go to the station within the distance
                    which has the lowest unit price
                  2.within the max distance, there is a gas station whose unit price lower
                    than the current station's, refill the gas so that the car can reach the
                    station exactly
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

class GasStation {

    float unitGasPrice;
    float distance;

    public GasStation(String unitGasPrice, String distance) {
        this.unitGasPrice = Float.parseFloat(unitGasPrice);
        this.distance = Float.parseFloat(distance);
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] line = reader.readLine().split(" ");
        float cMax = Float.parseFloat(line[0]);     // the maximum capacity of the tank
        float D = Float.parseFloat(line[1]);        // the distance between Hangzhou and the destination city
        float dAvg = Float.parseFloat(line[2]);     // the average distance per unit gas that the car can run
        int N = Integer.parseInt(line[3]);          // the total number of gas stations

        float maxDistancePerTank = cMax * dAvg;        // max distance per tank of gas

        List<GasStation> gasStations = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            line = reader.readLine().split(" ");
            GasStation gs = new GasStation(line[0], line[1]);
            gasStations.add(gs);
        }

        // to set the destination's unit gas price 0
        gasStations.add(new GasStation("0", Float.toString(D)));

        // sort gas stations according to their distance
        Collections.sort(gasStations, new Comparator<GasStation>() {
            @Override
            public int compare(GasStation o1, GasStation o2) {
                if (o1.distance < o2.distance) {
                    return -1;
                }
                return 1;
            }
        });

        float cost = 0;     // the total cost of gas
        float leftGas = 0;      // the gas used left
        boolean reachDes = true;        //  the car don't reach the destination
        if (gasStations.get(0).distance != 0) {
            System.out.println("The maximum travel distance = 0.00");
        } else {
            int currentStation = 0;
            while (currentStation < N) {
                GasStation temp = gasStations.get(currentStation);
                // max distance the car can reach
                float maxDistance = maxDistancePerTank + temp.distance;
                int nextStation = currentStation + 1;
                // current gas station's price is the lowest
                boolean isLowestPrice = true;
                // init the lowest price and the index of the price
                float lowestPrice = gasStations.get(nextStation).unitGasPrice;
                int lowestIndex = nextStation;
                while (gasStations.get(nextStation).distance <= maxDistance) {
                    if (gasStations.get(nextStation).unitGasPrice < temp.unitGasPrice) {
                        isLowestPrice = false;
                        break;
                    }
                    // get the lowest price among stations
                    // within the max distance except the current station
                    if (gasStations.get(nextStation).unitGasPrice <= lowestPrice) {
                        lowestPrice = gasStations.get(nextStation).unitGasPrice;
                        lowestIndex = nextStation;
                    }
                    nextStation++;
                }

                // the car can't reach the next gas station
                if (gasStations.get(currentStation + 1).distance > maxDistance) {
                    reachDes = false;
                    System.out.printf("The maximum travel distance = %.2f", maxDistance);
                    break;
                } else {
                    if (isLowestPrice) {
                        cost += (cMax - leftGas) * temp.unitGasPrice;
                        leftGas = cMax;         //  fill up the gas
                        leftGas -= (gasStations.get(lowestIndex).distance
                                - temp.distance) / dAvg;
                        currentStation = lowestIndex;
                    } else {
                        float gasNeeded = (gasStations.get(nextStation).distance
                                - temp.distance) / dAvg;
                        if (leftGas <= gasNeeded) {
                            cost += (gasNeeded - leftGas) * temp.unitGasPrice;
                            leftGas = gasNeeded;
                        }
                        leftGas -= (gasStations.get(nextStation).distance
                                - temp.distance)/dAvg;
                        currentStation = nextStation;
                    }
                }


            }
            if (reachDes) {
                System.out.printf("%.2f", cost);
            }
        }
    }
}
