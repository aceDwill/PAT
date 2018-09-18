/*
	思路:用数组来存储数据，下标表示指数，值表示系数，
		 输出值不为0的项
*/


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] first_line = reader.readLine().split(" ");
        String[] second_line = reader.readLine().split(" ");
        // 存储两个多项式
        float[] first_polynomials = new float[1010];
        float[] second_polynomials = new float[1010];
        int k1 = Integer.parseInt(first_line[0]);
        int k2 = Integer.parseInt(second_line[0]);
        for (int i = 1; i < 2 * k1; i += 2) {
            int n1 = Integer.parseInt(first_line[i]);
            float an1 = Float.parseFloat(first_line[i + 1]);
            first_polynomials[n1] = an1;
        }
        for (int i = 1; i < 2 * k2; i += 2) {
            int n2 = Integer.parseInt(second_line[i]);
            float an2 = Float.parseFloat(second_line[i + 1]);
            second_polynomials[n2] = an2;
        }

        int cnt = 0; // 记录系数不为0的项数
        for (int i = 0; i < 1010; i++) {
            first_polynomials[i] += second_polynomials[i];
            if (first_polynomials[i] != 0.0) {
                cnt++;
            }
        }
        System.out.print(cnt);
        for (int i = 1005; i >= 0; i--) {
            if (first_polynomials[i] != 0.0) {
                System.out.printf(" %d %.1f", i, first_polynomials[i]);
            }
        }

    }
}
