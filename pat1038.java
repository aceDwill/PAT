//      attention: test case 6 Time Limit Exceeded

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] line = reader.readLine().split(" ");
        Arrays.sort(line, 1, line.length, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return (o1 + o2).compareTo(o2 + o1);
            }
        });


        String result = "";

        for (int i = 1; i < line.length; i++) {
            result += line[i];
        }

        // erase 0 in front of the number
        result = result.replaceFirst("^0*", "");

        if (result.length() == 0) {
            System.out.println(0);
        } else {
            System.out.println(result);
        }
    }
}
