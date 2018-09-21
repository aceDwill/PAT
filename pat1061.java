import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        String[] week = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String line1 = reader.readLine();
        String line2 = reader.readLine();
        String line3 = reader.readLine();
        String line4 = reader.readLine();
        int len1 = Math.min(line1.length(), line2.length());
        int len2 = Math.min(line3.length(), line4.length());
        int breakIndex = 0;     // 第一次遇到大写字母相等时的索引
        for (int i = 0; i < len1; i++) {
            char c1 = line1.charAt(i);
            char c2 = line2.charAt(i);
            if (c1 == c2 && c1 >= 'A' && c1 <= 'G') {
                System.out.print(week[c1 - 'A']);
                breakIndex = i + 1;
                break;
            }
        }

        for (int i = breakIndex; i < len1; i++) {
            char c1 = line1.charAt(i);
            char c2 = line2.charAt(i);
            if (c1 == c2) {
                if (Character.isDigit(c1)) {
                    System.out.printf(" %02d:", c1 - '0');
                    break;
                }
                if (c1 >= 'A' && c1 <= 'N') {
                    System.out.printf(" %02d:", c1 - 'A' + 10);
                    break;
                }

            }
        }

        for (int i = 0; i < len2; i++) {
            char c1 = line3.charAt(i);
            char c2 = line4.charAt(i);
            if (c1 == c2 && Character.isLetter(c1)) {
                System.out.printf("%02d", i);
                break;
            }

        }
    }
}
