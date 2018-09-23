import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        String[] numOfCN = {"zero", "one", "two", "three", "four",
                "five", "six", "seven", "eight", "nine"};
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String line = reader.readLine();
        int sumOfDigits = 0;
        for (int i = 0; i < line.length(); i++) {
            sumOfDigits += line.charAt(i) - '0';
        }
        String sumInString = Integer.toString(sumOfDigits);     // 将和转化化字符串形式
        for (int i = 0; i < sumInString.length(); i++) {
            System.out.print(numOfCN[sumInString.charAt(i) - '0']);
            if (i != sumInString.length() - 1) {
                System.out.print(" ");
            }
        }
    }
}
