/*
    Solution: 1.use book[] to convert char to number
              2.convert the chosen number to decimal ,assign it temp
              3.assign (the max number of all digits) + 1 to left,
                assign max(temp,left)+1 to right,
              4.use binary search to find the radix
    attention: 1.the max radix is not 36, radix >= 2
               2.input: 9 9 1 7 ,this test case should output "Impossible",
                 not 10
               3.Integer may be overflow,use long
 */

import java.util.Scanner;

public class Main {
    static int[] book = new int[200];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String n1 = sc.next();
        String n2 = sc.next();
        int tag = sc.nextInt();
        int radix = sc.nextInt();

        for (char i = '0'; i <= '9'; i++) {
            book[i] = i - '0';
        }
        for (char i = 'a'; i <= 'z'; i++) {
            book[i] = i - 'a' + 10;
        }
        long temp;
        String n;   // the num to be addressed
        if (tag == 1) {
            temp = convert10(n1, radix);
            n = n2;
        } else {
            temp = convert10(n2, radix);
            n = n1;
        }

        if (temp == -1) {
            System.out.println("Impossible");
            return;
        }

        long left = findMaxNum(n) + 1;
        long right = Math.max(left, temp) + 1;
        long result = binarySearch(left, right, temp, n);
        if (result == -1) {
            System.out.println("Impossible");
        } else {
            System.out.println(result);
        }

    }

    // convert num to decimal
    static long convert10(String s, long radix) {
        long result = 0;
        for (int i = 0; i < s.length(); i++) {
            // num of a certain digit >= radix, can't convert decimal
            if (book[s.charAt(i)] >= radix) {
                return -1;
            } else {
                result = result * radix + book[s.charAt(i)];
            }
        }
        return result;
    }

    static long binarySearch(long left, long right, long n1, String n2) {
        while (left <= right) {
            long mid = (left + right) / 2;
            long temp = convert10(n2, mid);
            // temp may overflow
            if (temp < 0 || temp > n1) {
                right = mid - 1;
            } else if (temp < n1) {
                left = mid + 1;
            } else {
                return mid;
            }
        }
        // can't find the radix
        return -1;
    }

    // find the max number of all digits
    static int findMaxNum(String s) {
        int result = -1;
        for (int i = 0; i < s.length(); i++) {
            if (book[s.charAt(i)] > result) {
                result = book[s.charAt(i)];
            }
        }
        return result;
    }
}
