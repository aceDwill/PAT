/*
    思路：1.将所有字符串反转，便于后续处理，并求出最短字符串长度
          2.从0索引比较所有反转字符串各字符是否相等
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(reader.readLine());
        StringBuilder[] lines = new StringBuilder[110];
        int minLen = 300;       // 记录字符串最短长度
        for (int i = 0; i < N; i++) {
            lines[i] = new StringBuilder(reader.readLine()).reverse();      // 反转字符串，便于处理
            if (lines[i].length() < minLen) {
                minLen = lines[i].length();
            }
        }
        int suffixIndex = 0;    // 记录字符串不等时的索引
        for (int i = 0; i < minLen; i++) {
            char commonC = lines[0].charAt(i);  // 依次把第一个字符串的字符默认为共同字符
            boolean hasSuffix = true;           // 存在相同字符
            for (int j = 1; j < N; j++) {
                if (lines[j].charAt(i) != commonC) {
                    hasSuffix = false;
                    break;
                }
            }
            if (hasSuffix) {
                suffixIndex++;
            } else {
                break;
            }
        }
        if (suffixIndex == 0) {
            System.out.println("nai");
        } else {
            // 求出共同字符串，此时处于反转状态
            String suffixReverse = lines[0].substring(0, suffixIndex);
            System.out.println(new StringBuilder(suffixReverse).reverse());
        }

    }
}
