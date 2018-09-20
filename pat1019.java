/*
        思路：用一个集合对B进制的各个数位进行存储，然后判断是不是回文数
        注意：虽然题目中N>0,但还是要考虑N=0的情况，否则测试点5不能通过
 */


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] line = reader.readLine().split(" ");
        int N = Integer.parseInt(line[0]);
        int B = Integer.parseInt(line[1]);
        ArrayList<Integer> result = new ArrayList<>();
        if (N == 0) {
            System.out.println("Yes");
            System.out.println(0);

        } else {
            while (N != 0) {
                result.add(N % B);
                N /= B;
            }
            boolean isPalindromic = true;
            int len = result.size();
            for (int i = 0; i < len / 2; i++) {
                if (!result.get(i).equals(result.get(len - i - 1))) {
                    isPalindromic = false;
                    break;
                }
            }

            if (isPalindromic) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
            System.out.print(result.get(len - 1));
            for (int i = len - 2; i >= 0; i--) {
                System.out.print(" " + result.get(i));
            }


        }
    }
}