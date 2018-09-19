import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        double profit = 1;
        String[] allResults = {"W", "T", "L"};
        double[] odds = new double[3];
        int max_odds_index = 0;
        for (int i = 0; i < 3; i++) {
            double max_odds = 0;
            String[] line = reader.readLine().split(" ");
            for (int j = 0; j < 3; j++) {
                odds[j] = Double.parseDouble(line[j]);
                if (odds[j] > max_odds) {
                    // 更新最大概率和最大概率索引
                    max_odds_index = j;
                    max_odds = odds[j];
                }
            }
            System.out.print(allResults[max_odds_index] + " ");
            profit *= max_odds;
        }

        profit = (profit * 0.65 - 1) * 2;
        System.out.printf("%.2f", profit);

    }
}
