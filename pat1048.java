/*
        attention: test case 3,4 Time Limit Exceeded
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] line = reader.readLine().split(" ");
        int N = Integer.parseInt(line[0]);
        int M = Integer.parseInt(line[1]);
        int[] coinValues = new int[510];
        line = reader.readLine().split(" ");
        for (int i = 0; i < N; i++) {
            coinValues[Integer.parseInt(line[i])]++;
        }

        boolean hasSolution = false;

        for (int i = 1; i < 510; i++) {
            // if value of coin is great than the amount / 2,there will be no solution
            if (i > M / 2) {
                break;
            }
            if (coinValues[i] != 0 && coinValues[M - i] != 0) {
                if (i == M - i) {
                    if (coinValues[i] > 1) {
                        hasSolution = true;
                        System.out.println(i + " " + i);
                        break;
                    }

                } else {
                    hasSolution = true;
                    System.out.println(i + " " + (M - i));
                    break;
                }
            }
        }

        if (!hasSolution){
            System.out.println("No Solution");
        }
    }
}
