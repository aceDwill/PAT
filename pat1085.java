// attention: test case 4 Time Limit Exceeded

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] line = reader.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        long p = Long.parseLong(line[1]);
        line = reader.readLine().split(" ");
        int[] seq = new int[n];
        for (int i = 0; i < n; i++) {
            seq[i] = Integer.parseInt(line[i]);
        }

        Arrays.sort(seq);
        int max_num = 0, temp = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + max_num; j < n; j++) {
                if (seq[j] <= seq[i] * p) {
                    temp = j - i + 1;
                    max_num = Math.max(max_num, temp);
                }else {
                    break;
                }
            }
        }
        System.out.println(max_num);
    }
}
