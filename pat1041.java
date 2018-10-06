/*
        attention: test case 4,5 Time Limit Exceeded sometimes
 */


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] line = reader.readLine().split(" ");
        int[] numBook = new int[10010];
        for (int i = 1; i < line.length; i++) {
            int betNum = Integer.parseInt(line[i]);
            numBook[betNum] += 1;
        }

        boolean noWinner = true;
        for (int i = 1; i < line.length; i++) {
            int betNum = Integer.parseInt(line[i]);
            if (numBook[betNum] == 1){
                System.out.println(betNum);
                noWinner = false;
                break;
            }
        }

        if (noWinner){
            System.out.println("None");
        }
    }
}
