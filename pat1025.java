// 第三个测试点运行超时

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

class Student {

    String regNum;      // 注册码
    int score;          // 分数
    int locationNum;    // 考试地点码
    int finalRank;      // 统一排名
    int localRank;      // 某个考试点排名

    public Student(String regNum, String score) {
        this.regNum = regNum;
        this.score = Integer.parseInt(score);
    }
}

class ScoreCmp implements Comparator<Student> {

    @Override
    public int compare(Student o1, Student o2) {
        if (o1.score != o2.score) {
            return o2.score - o1.score;
        } else {
            return o1.regNum.compareTo(o2.regNum);
        }
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(reader.readLine());        // 共有多少考试地点
        ArrayList<Student> students = new ArrayList<>();
        for (int i = 1; i <= N; i++) {
            int K = Integer.parseInt(reader.readLine());
            ArrayList<Student> someStudents = new ArrayList<>();
            for (int j = 0; j < K; j++) {
                String[] line = reader.readLine().split(" ");
                Student student = new Student(line[0], line[1]);
                student.locationNum = i;
                someStudents.add(student);
                students.add(student);
            }
            Collections.sort(someStudents, new ScoreCmp());
            someStudents.get(0).localRank = 1;
            for (int k = 1; k < someStudents.size(); k++) {
                // 分数相同，排名相同
                if (someStudents.get(k).score == someStudents.get(k - 1).score) {
                    someStudents.get(k).localRank = someStudents.get(k - 1).localRank;
                } else {
                    someStudents.get(k).localRank = k + 1;
                }
            }
        }
        Collections.sort(students, new ScoreCmp());
        students.get(0).finalRank = 1;
        for (int i = 1; i < students.size(); i++) {
            if (students.get(i).score == students.get(i - 1).score) {
                students.get(i).finalRank = students.get(i - 1).finalRank;
            } else {
                students.get(i).finalRank = i + 1;
            }
        }

        System.out.println(students.size());
        for (int i = 0; i < students.size(); i++) {
            Student temp = students.get(i);
            System.out.println(temp.regNum + " " + temp.finalRank
                    + " " + temp.locationNum + " " + temp.localRank);
        }

    }
}
