/*
        思路：将数划分为四位区间，然后分别处理
 */

import java.io.BufferedReader;
        import java.io.IOException;
        import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        String[] numInCN = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
        String[] digitsInCN = {"Shi", "Bai", "Qian", "Wan", "Yi"};
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String s = reader.readLine();
        String result = "";         // 存储最后结果
        if (s.charAt(0) == '-') {
            result += "Fu";
            s = s.substring(1);
        }

        int left = 0;
        int right = s.length() - 1;
        while (left + 4 <= right) {
            right -= 4;
        }
        // 只有一位数的情况
        if (s.length() == 1) {
            result +=" " + numInCN[s.charAt(0) - '0'];
        }

        while (left < s.length() - 1) {
            boolean hasAdded = false;         // 四位数中是否有数位添加
            boolean hasMoreZero = false;    // 是否存在连续零
            while (left <= right) {
                if (s.charAt(left) == '0') {
                    hasMoreZero = true;     // 存在一个零以上
                } else {
                    if (hasMoreZero) {
                        result += " ling";
                        hasMoreZero = false;
                    }
                    result += " " + numInCN[s.charAt(left) - '0'];
                    hasAdded = true;        // 表示处理的四位区间有数添加进来

                }
                // 处理区间到末尾的情况
                if (left == right) {
                    if (left == s.length() - 1) {   // 处理到最后一位直接跳出循环
                        break;
                    } else {
                        // 每四位结束输出后该输出Yi还是Wan
                        if (hasAdded) {         // 有数添加进来则要输出亿或者万
                            result += " " + digitsInCN[(s.length() - left) / 4 + 2];
                        }
                    }
                } else {
                    // 除0之外的数添加其数位
                    if (!hasMoreZero) {
                        result += " " + digitsInCN[right - left - 1];  // 添加十百千
                    }
                }
                left++;
            }
            right += 4;
        }
        // 处理掉输出结果最前面可能出现的空格
        System.out.println(result.trim());

    }
}

