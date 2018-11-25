// attention: test case 1,2,3,4,5 Time Limit Exceeded

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(reader.readLine());
        String[] line = reader.readLine().split(" ");
        int[] nums = new int[n];
        int[] numsSorted = new int[n];
        for (int i = 0; i < n; i++) {
            int temp = Integer.parseInt(line[i]);
            nums[i] = temp;
            numsSorted[i] = temp;
        }

        Arrays.sort(numsSorted);
        List<Integer> results = new ArrayList<>();

        int maxNum = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == numsSorted[i] && nums[i] > maxNum) {
                results.add(nums[i]);
            }
            if (nums[i] > maxNum) {
                maxNum = nums[i];
            }
        }

        System.out.println(results.size());
        if (results.size() != 0) {
            System.out.print(results.get(0));
            for (int i = 1; i < results.size(); i++) {
                System.out.print(" " + results.get(i));
            }
        }else {
            System.out.println();
        }

    }
}
