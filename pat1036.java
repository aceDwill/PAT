/*
       思路：在输入原始数据时进行比较，记录最低成绩男生情况和最高成绩女生情况
 */


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        int lowestGrade = 101;
        int highestGrade = -1;
        String femaleName = null;
        String femaleID = null;
        String maleName = null;
        String maleID = null;

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(reader.readLine());
        for (int i = 0; i < N; i++) {
            String[] line = reader.readLine().split(" ");
            if (line[1].equals("M")) {
                int maleGrade = Integer.parseInt(line[3]);
                // 记录最低成绩男生情况
                if (maleGrade < lowestGrade) {
                    maleName = line[0];
                    maleID = line[2];
                    lowestGrade = maleGrade;
                }
            } else {
                int femaleGrade = Integer.parseInt(line[3]);
                // 记录最高成绩女生情况
                if (Integer.parseInt(line[3]) > highestGrade) {
                    femaleName = line[0];
                    femaleID = line[2];
                    highestGrade = femaleGrade;
                }
            }
        }

        boolean isAbsent = false;   // 记录是否有女生或男生缺席
        if (highestGrade == -1) {
            System.out.println("Absent");
            isAbsent = true;
        } else {
            System.out.println(femaleName + " " + femaleID);
        }

        if (lowestGrade == 101) {
            System.out.println("Absent");
            isAbsent = true;
        } else {
            System.out.println(maleName + " " + maleID);
        }

        if (isAbsent) {
            System.out.println("NA");
        } else {
            System.out.println(highestGrade - lowestGrade);
        }

    }
}
