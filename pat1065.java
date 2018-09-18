/*
        思路：对溢出情况进行讨论即可
 */



import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        Long a, b, c;
        for (int i = 0; i < T; i++) {
            a = sc.nextLong();
            b = sc.nextLong();
            c = sc.nextLong();
            // a+b溢出的两种情况处理
            if (a > 0 && b > 0 && a + b < 0) {
                System.out.println("Case #" + (i + 1) + ": true");
                continue;
            } else if (a < 0 && b < 0 && a + b >= 0) { //   两个最小负数溢出为0
                System.out.println("Case #" + (i + 1) + ": false");
                continue;
            }

            if (a + b > c) {
                System.out.println("Case #" + (i + 1) + ": true");
            } else {
                System.out.println("Case #" + (i + 1) + ": false");
            }

        }
    }
}


// 用BigInteger方法求解


/*
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(reader.readLine());
        for (int i = 1; i <= T; i++) {
            String[] line = reader.readLine().split(" ");
            BigInteger A = new BigInteger(line[0]);
            BigInteger B = new BigInteger(line[1]);
            BigInteger C = new BigInteger(line[2]);
            if ((A.add(B)).compareTo(C) > 0) {
                System.out.println("Case #" + i + ": true");
            } else {
                System.out.println("Case #" + i + ": false");
            }
        }
    }
}
*/