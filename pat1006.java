/*
        思路：用一个集合存储所有学生，然后按要求进行排序
 */


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

class Student {
    String ID_number;
    // 将登入登出数据处理成整型
    int sign_in_hour;
    int sign_in_min;
    int sign_in_sec;
    int sign_out_hour;
    int sign_out_min;
    int sign_out_sec;

    // 初始数据
    public Student(String ID_number, String sign_in_time, String sign_out_time) {
        String[] sign_in = sign_in_time.split(":");
        String[] sign_out = sign_out_time.split(":");
        this.ID_number = ID_number;
        this.sign_in_hour = Integer.parseInt(sign_in[0]);
        this.sign_in_min = Integer.parseInt(sign_in[1]);
        this.sign_in_sec = Integer.parseInt(sign_in[2]);
        this.sign_out_hour = Integer.parseInt(sign_out[0]);
        this.sign_out_min = Integer.parseInt(sign_out[1]);
        this.sign_out_sec = Integer.parseInt(sign_out[2]);
    }

}

// 对登入时间排序逻辑
class SignInComparator implements Comparator<Student> {

    @Override
    public int compare(Student o1, Student o2) {
        if (o1.sign_in_hour != o2.sign_in_hour) {
            return o1.sign_in_hour - o2.sign_in_hour;
        } else if (o1.sign_in_min != o2.sign_in_min) {
            return o1.sign_in_min - o2.sign_in_min;
        } else {
            return o1.sign_in_sec - o2.sign_in_sec;
        }
    }
}

// 对登出时间排序逻辑
class SignOutComparator implements Comparator<Student> {

    @Override
    public int compare(Student o1, Student o2) {
        if (o1.sign_out_hour != o2.sign_out_hour) {
            return o2.sign_out_hour - o1.sign_out_hour;
        } else if (o1.sign_out_min != o2.sign_out_min) {
            return o2.sign_out_min - o1.sign_out_min;
        } else {
            return o2.sign_out_sec - o1.sign_out_sec;
        }
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int M = Integer.parseInt(reader.readLine());
        ArrayList<Student> students = new ArrayList<>();
        for (int i = 0; i < M; i++) {
            String[] line = reader.readLine().split(" ");
            Student s = new Student(line[0], line[1], line[2]);
            students.add(s);
        }

        Collections.sort(students, new SignInComparator());
        System.out.print(students.get(0).ID_number + " ");
        Collections.sort(students, new SignOutComparator());
        System.out.println(students.get(0).ID_number);
    }

}


