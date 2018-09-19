/*
        思路：用一个double数组存储多项式，
              索引--多项式指数，值--多项式系数，
              多项式相乘后输出最后结果
 */


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        // 存储输入数据
        String[] first_line = reader.readLine().split(" ");
        String[] second_line = reader.readLine().split(" ");
        int K1 = Integer.parseInt(first_line[0]);       // 第一个多项式项数
        int K2 = Integer.parseInt(second_line[0]);      // 第二个多项式项数
        // 用double数组存储多项式的系数(对应数组值)和指数(对应数组索引)
        double[] result_polynomial = new double[2010];

        for (int i = 1; i < 2 * K1; i += 2) {
            int n1 = Integer.parseInt(first_line[i]);
            double an1 = Double.parseDouble(first_line[i + 1]);

            for (int j = 1; j < 2 * K2; j += 2) {
                int n2 = Integer.parseInt(second_line[j]);
                double an2 = Double.parseDouble(second_line[j + 1]);
                int n3 = n1 + n2;
                double an3 = an1 * an2;
                // 记录两个多项式相乘结果
                result_polynomial[n3] += an3;
            }
        }

        int cnt = 0;    // 记录系数不为0的项数
        for (int i = 0; i < 2010; i++) {
            if (result_polynomial[i] != 0) {
                cnt++;
            }
        }
        System.out.print(cnt);
        for (int i = 2005; i >= 0; i--) {
            if (result_polynomial[i] != 0) {
                System.out.printf(" %d %.1f", i, result_polynomial[i]);
            }
        }

    }
}