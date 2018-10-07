/*
        attention: test case 1,3 Time Limit Exceeded
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String s1 = reader.readLine();
        String s2 = reader.readLine();
        int[] charBook = new int[200];      // save chars which hava showed
        for (int i = 0; i < s2.length(); i++) {
            charBook[s2.charAt(i)]++;
        }
        for (int i = 0; i < s1.length(); i++) {
            if (charBook[s1.charAt(i)] == 0){
                System.out.print(s1.charAt(i));
            }
        }
    }
}
