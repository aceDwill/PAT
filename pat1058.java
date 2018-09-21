import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] line = reader.readLine().split(" ");
        System.out.println(addInHogwarts(line[0], line[1]));
    }

    static String addInHogwarts(String A, String B) {
        String[] numA = A.split("\\.");
        String[] numB = B.split("\\.");
        int[] result = new int[3];
        // 将各位相加
        int knut = Integer.parseInt(numA[2]) + Integer.parseInt(numB[2]);
        int sickle = Integer.parseInt(numA[1]) + Integer.parseInt(numB[1]);
        int galleon = Integer.parseInt(numA[0]) + Integer.parseInt(numB[0]);
        if (knut >= 29) {
            // knut位有进位情况
            knut -= 29;
            sickle += 1;
        }
        if (sickle >= 17) {
            // sickle位有进位情况
             sickle -= 17;
            galleon += 1;
        }

        return galleon + "." + sickle + "." + knut;
    }

}
