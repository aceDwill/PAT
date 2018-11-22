/*
    solution: 1.use sumOf1toj to save sum of diamond 1 to j;
              2.if sumOf1toj[right] - sumOf1toj[left] == m ,add string "left-right" to solution
              3.if sumOf1toj[right] - sumOf1toj[left] < m, left ++
              4.if sumOf1toj[right] - sumOf1toj[left] > m, right ++
    attention：test case 3 Time Limit Exceeded
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] line = reader.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int m = Integer.parseInt(line[1]);
        line = reader.readLine().split(" ");
        int[] sumOf1toj = new int[n + 1];   // sum of Diamond 1 to Diamond j
        for (int i = 1; i <= n; i++) {
            int temp = Integer.parseInt(line[i - 1]);
            sumOf1toj[i] = temp + sumOf1toj[i - 1];
        }
        boolean hasSolution = false;     // has solution which Di + ... + Dj = M
        int left = 0;
        int right = 1;
        while (sumOf1toj[right] < m) {
            right++;
        }
        List<String> solutions = new ArrayList<>(); // all solutions
        int min_sum = 100000010;
        while (right <= n) {
            int tempSum = sumOf1toj[right] - sumOf1toj[left];
            String tempSolution = (left + 1) + "-" + right;
            if (tempSum == m) {
                if (hasSolution) {
                    solutions.add(tempSolution);
                } else {
                    solutions.clear();
                    solutions.add(tempSolution);
                    hasSolution = true;
                }
                left++;
                right++;
            } else if (tempSum < m) {
                right++;
            } else {
                left++;
                if (!hasSolution) {
                    if (tempSum < min_sum) {
                        min_sum = tempSum;
                        solutions.clear();  // clear the previous solutions
                        solutions.add(tempSolution);
                    } else if (tempSum == min_sum) {
                        solutions.add(tempSolution);
                    }
                }
            }
        }
        for (String s : solutions) {
            System.out.println(s);
        }
    }
}
