/*
        attention: test case 4 is Time Limit Exceeded when using Scanner to get input while
                   test case 1 is wrong when using BufferedReader to get input
 */

import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int nc = sc.nextInt();

        int[] coupons = new int[nc];
        int positiveCouponNum = 0;      // the num of the coupons with positive values
        int positiveProductNum = 0;     // the num of the products with positive values
        for (int i = 0; i < nc; i++) {
            coupons[i] = sc.nextInt();
            if (coupons[i] > 0) {
                positiveCouponNum++;
            }
        }

        int np = sc.nextInt();
        int[] products = new int[np];
        for (int i = 0; i < np; i++) {
            products[i] = sc.nextInt();
            if (products[i] > 0) {
                positiveProductNum++;
            }
        }

        int maxMoney = 0;
        Arrays.sort(coupons);
        Arrays.sort(products);


        int len1 = Math.min(nc - positiveCouponNum, np - positiveProductNum);
        int len2 = Math.min(positiveCouponNum, positiveProductNum);
        for (int i = 0; i < len1; i++) {
            maxMoney += coupons[i] * products[i];
        }
        for (int i = 0; i < len2; i++) {
            maxMoney += coupons[nc - i - 1] * products[np - i - 1];
        }

        System.out.println(maxMoney);
    }
}
