import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        int[] lettersBook = new int[100];       // to save letters which have showed
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String original = reader.readLine().toUpperCase();
        String typeOut = reader.readLine().toUpperCase();

        for (int i = 0; i < typeOut.length(); i++) {
            lettersBook[typeOut.charAt(i) - '0']++;

        }

        for (int i = 0; i < original.length(); i++) {
            if (lettersBook[original.charAt(i) - '0'] == 0) {
                System.out.print(original.charAt(i));
                lettersBook[original.charAt(i) - '0']++;
            }
        }
    }
}
