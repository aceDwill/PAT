/*
        solution: 1.sort cars' plate and time
                  2.find two records which are well paired,calculate the parking time
                  3.sort cars' time
                  4.print the number of cars parking on campus before the query time
                  5.print cars' plate which has the longest parking time and the time
        attention: test case 1,2,4,5 Time Limit Exceeded

 */


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Car {

    String plateNumber;
    int time;       // convert time to seconds
    String status;

    public Car(String plateNumber, String time, String status) {
        String[] timeArray = time.split(":");
        this.plateNumber = plateNumber;
        this.time = Integer.parseInt(timeArray[0]) * 3600
                + Integer.parseInt(timeArray[1]) * 60 + Integer.parseInt(timeArray[2]);
        this.status = status;
    }

    // compare car's parking time with query time
    public boolean compareTime(String queryTime) {
        String[] timeArray = queryTime.split(":");
        int[] time = new int[3];
        for (int i = 0; i < 3; i++) {
            time[i] = Integer.parseInt(timeArray[i]);
        }
        return this.time <= time[0] * 3600 + time[1] * 60 + time[2];
    }

}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] line = reader.readLine().split(" ");
        int N = Integer.parseInt(line[0]);      // number of records
        int K = Integer.parseInt(line[1]);      // number of queries

        List<Car> cars = new ArrayList<>();
        List<Car> validCars = new ArrayList<>();       //   remove invalid cars

        for (int i = 0; i < N; i++) {
            line = reader.readLine().split(" ");
            Car car = new Car(line[0], line[1], line[2]);
            cars.add(car);
        }

        String[] queryTime = new String[K];     // save query time
        for (int i = 0; i < K; i++) {
            queryTime[i] = reader.readLine();
        }

        // sort their name first then time
        Collections.sort(cars, new Comparator<Car>() {
            @Override
            public int compare(Car o1, Car o2) {
                if (o1.plateNumber.compareTo(o2.plateNumber) != 0) {
                    return o1.plateNumber.compareTo(o2.plateNumber);
                }
                return o1.time - o2.time;
            }
        });


        Map<String, Integer> carParkingTime = new TreeMap<>();    // cars' total parking time
        int maxParkingTime = -1;     // the longest parking time
        for (int i = 0; i < N - 1; i++) {
            Car tempCar = cars.get(i);
            Car nextCar = cars.get(i + 1);
            //  car's in and out records are well paired
            if (tempCar.plateNumber.equals(nextCar.plateNumber) &&
                    tempCar.status.equals("in") && nextCar.status.equals("out")) {
                validCars.add(tempCar);
                validCars.add(nextCar);
                int onceParkingTime = nextCar.time - tempCar.time;
                // the car's plate number not in the map, assign 0
                if (!carParkingTime.containsKey(tempCar.plateNumber)) {
                    carParkingTime.put(tempCar.plateNumber, 0);
                }
                // get previous total parking time
                int previousParkingTime = carParkingTime.get(tempCar.plateNumber);
                previousParkingTime += onceParkingTime;
                // update total parking time
                carParkingTime.put(tempCar.plateNumber, previousParkingTime);
                // update max parking time
                maxParkingTime = Math.max(maxParkingTime,
                        carParkingTime.get(tempCar.plateNumber));
                i++;        // next car is "out",skip it
            }
        }

        Collections.sort(validCars, new Comparator<Car>() {
            @Override
            public int compare(Car o1, Car o2) {
                return o1.time - o2.time;
            }
        });

        int now = 0;        // current car before query time
        int numCar = 0;     // number of cars parking on campus
        for (int i = 0; i < K; i++) {
            while (now < validCars.size() && validCars.get(now).compareTime(queryTime[i])) {
                if (validCars.get(now).status.equals("in")) {
                    numCar++;
                } else {
                    numCar--;
                }
                now++;
            }
            System.out.println(numCar);
        }

        for (Map.Entry<String, Integer> entry : carParkingTime.entrySet()) {
            // print plate of the longest parking time cars'
            if (entry.getValue() == maxParkingTime) {
                System.out.print(entry.getKey() + " ");
            }
        }

        // print max parking time
        System.out.printf("%02d:%02d:%02d\n", maxParkingTime / 3600,
                maxParkingTime % 3600 / 60, maxParkingTime % 60);

    }
}
