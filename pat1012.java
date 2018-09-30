/*
        思路：1.创建学生类，成员变量为分数数组和排名数组
              2.对每门课程进行排序，将其排名存入排名数组对应位置
              3.查询过程中，按优先级找到最好排名将其输出
        注：测试点4随机出现超时情况,多提交几次会通过
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

class Student {

    int[] grades = new int[4];   // 依次记录A,C,M,E的分数
    int[] ranks = new int[4];   // 依次记录A,C,M,E的排名

    public Student(String CGrade, String MGrade, String EGrade) {
        grades[1] = Integer.parseInt(CGrade);
        grades[2] = Integer.parseInt(MGrade);
        grades[3] = Integer.parseInt(EGrade);
        grades[0] = grades[1] + grades[2] + grades[3];
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] line = reader.readLine().split(" ");
        String[] indexToCourse = {"A", "C", "M", "E"};      // 将索引转换为对应课程
        int N = Integer.parseInt(line[0]);
        int M = Integer.parseInt(line[1]);

        Student[] students = new Student[1000000];  // 用索引记录学生ID
        ArrayList<Student> arrayForSort = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            line = reader.readLine().split(" ");
            int SID = Integer.parseInt(line[0]);
            students[SID] = new Student(line[1], line[2], line[3]);
            arrayForSort.add(students[SID]);
        }

        for (int i = 0; i < 4; i++) {
            final int finalI = i;
            // 对相应课程进行排序
            Collections.sort(arrayForSort, new Comparator<Student>() {
                @Override
                public int compare(Student o1, Student o2) {
                    return o2.grades[finalI] - o1.grades[finalI];
                }
            });


            // 记录相应课程排名
            arrayForSort.get(0).ranks[i] = 1;
            for (int j = 1; j < arrayForSort.size(); j++) {
                Student s1 = arrayForSort.get(j - 1);
                Student s2 = arrayForSort.get(j);
                if (s2.grades[i] == s1.grades[i]) {
                    s2.ranks[i] = s1.ranks[i];
                } else {
                    s2.ranks[i] = j + 1;
                }
            }
        }

        for (int i = 0; i < M; i++) {
            int searchID = Integer.parseInt(reader.readLine());
            Student temp = students[searchID];
            if (temp == null) {
                System.out.println("N/A");
            } else {
                int indexForBestRank = 0;
                // 按优先级找到最好课程排名
                for (int j = 1; j < 4; j++) {
                    if (temp.ranks[indexForBestRank] > temp.ranks[j]) {
                        indexForBestRank = j;
                    }
                }
                System.out.println(temp.ranks[indexForBestRank] + " " +
                        indexToCourse[indexForBestRank]);
            }
        }

    }
}
