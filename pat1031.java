/*
        思路：找出满足条件的垂直高度，然后按要求输出字符串

 */


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String line = reader.readLine();
        int len = line.length();
        int nMax = 0;   // 最大n1和n3,即垂直的边长
        for (int i = 1; i < (len - 2 * i); i++) {
            nMax = i;
        }
        int blank_cnt = len - 2 * nMax - 2;     // 每行空格数量
        for (int i = 0; i < nMax; i++) {
            System.out.print(line.charAt(i));
            for (int j = 0; j < blank_cnt; j++) {
                System.out.print(" ");
            }
            System.out.println(line.charAt(len - i - 1));
        }
        // 输出底边的字符
        for (int i = nMax; i < (len - nMax); i++) {
            System.out.print(line.charAt(i));
        }


    }
}
