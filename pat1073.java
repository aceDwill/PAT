/*
        思路：分为指数小于0和大于等于0情况讨论
              大于等于0情况又分为
              1.指数为0情况
              2.不存在小数点，后面添零
              3.存在小数点，不需要再添零
        注意：测试点5，6超时
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] line = reader.readLine().split("E");
        int exp = Integer.parseInt(line[1]);
        String result = "";
        if (line[0].charAt(0) == '-') {
            result += "-";
        }
        // 指数小于0的情况
        if (exp < 0) {
            result += "0.";
            for (int i = exp + 1; i < 0; i++) {
                result += "0";
            }
            result += line[0].charAt(1) + line[0].substring(3);   // 将中间的小数点跳过
        } else {
            int temp = exp - (line[0].length() - 3);     // 指数减去小数点后数位情况
            if (temp >= 0) {            // 结果后面添零情况
                result += line[0].charAt(1) + line[0].substring(3);
                for (int i = 0; i < temp; i++) {
                    result += "0";
                }
            } else {
                // 中间添小数点的情况
                if (exp == 0) {
                    result += line[0].substring(1);
                } else {
                    result += line[0].charAt(1) + line[0].substring(3, 3 + exp)
                            + "." + line[0].substring(3 + exp);
                }
            }
        }

        System.out.println(result);
    }
}
