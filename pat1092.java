import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int[] colorBook = new int[200];     // save colors which hava showed
        String shopBeads = reader.readLine();
        String evaBeads = reader.readLine();
        for (int i = 0; i < shopBeads.length(); i++) {
            colorBook[shopBeads.charAt(i)]++;
        }

        int missingBeads = 0;
        boolean buy = true;
        for (int i = 0; i < evaBeads.length(); i++) {
            colorBook[evaBeads.charAt(i)]--;
            if (colorBook[evaBeads.charAt(i)] < 0) {
                buy = false;
                missingBeads++;
            }
        }


        if (buy) {
            System.out.println("Yes" + " " + (shopBeads.length() - evaBeads.length()));
        } else {
            System.out.println("No" + " " + missingBeads);
        }
    }
}
