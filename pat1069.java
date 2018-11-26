import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] num = new int[4];
        for (int i = 0; i < 4; i++) {
            num[i] = n % 10;
            n /= 10;
        }

        Arrays.sort(num);

        int result = -1;
        while (result != 0 && result != 6174) {
            int a = 0, b = 0;   // a-b = result
            for (int i = 3; i >= 0; i--) {
                a = a * 10 + num[i];
            }
            for (int i = 0; i < 4; i++) {
                b = b * 10 + num[i];
            }

            result = a - b;
            System.out.printf("%04d - %04d = %04d\n", a, b, result);

            int temp = result;
            for (int i = 0; i < 4; i++) {
                num[i] = temp % 10;
                temp /= 10;
            }

            Arrays.sort(num);

        }
    }
}
