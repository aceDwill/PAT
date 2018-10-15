/*
       solution: 1.create an array to save the index of number
                 2.if 0 is not at the index of 0,swap 0 and the number whose value equals the
                   index of 0
                 3.if 0 is at the index of 0,find out the first number not at the right index,
                   swap them
       attention: 1.test cases 1,2 Time Limit Exceeded sometimes
                  2.the sample input is like this
                    10
                    3 5 7 2 6 4 9 0 8 1
                    but the test cases is actually like this
                    10 3 5 7 2 6 4 9 0 8 1

 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] line = reader.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int[] seq = new int[n];
        int leftNum = n - 1;   // the number of numbers not in the right index except 0
        int[] indexOfNum = new int[100010];     // the index of numbers

        int numOfSwaps = 0;     // the number of swaps

        for (int i = 0; i < n; i++) {
            seq[i] = Integer.parseInt(line[i + 1]);
            indexOfNum[seq[i]] = i;

            if (seq[i] == i && i != 0) {
                leftNum--;
            }
        }

        int indexOf0 = 0, indexSwap = 0;     // the indexes of 0 and number to swap
        int k = 1;        // the first number not in the right index
        while (leftNum > 0) {
            indexOf0 = indexOfNum[0];
            if (indexOf0 != 0) {
                leftNum--;
                indexSwap = indexOfNum[indexOf0];
                indexOfNum[0] = indexSwap;
            } else {
                while (k < n) {
                    if (seq[k] != k) {
                        indexSwap = k;
                        // update the index of 0 and number to swap
                        indexOfNum[0] = k;
                        indexOfNum[seq[k]] = 0;
                        break;
                    }
                    k++;
                }
            }
            int temp = seq[indexOf0];
            seq[indexOf0] = seq[indexSwap];
            seq[indexSwap] = temp;

            numOfSwaps++;
        }

        System.out.println(numOfSwaps);
    }
}
