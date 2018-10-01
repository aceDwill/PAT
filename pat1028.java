/*
        思路：按要求排序即可
        注：测试点6超时
 */


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

class Student {

    String ID;
    String name;
    int grade;

    public Student(String ID, String name, String grade) {
        this.ID = ID;
        this.name = name;
        this.grade = Integer.parseInt(grade);
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] line = reader.readLine().split(" ");
        int N = Integer.parseInt(line[0]);
        int C = Integer.parseInt(line[1]);

        ArrayList<Student> students = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            line = reader.readLine().split(" ");
            Student s = new Student(line[0], line[1], line[2]);
            students.add(s);
        }

        if (C == 1) {
            Collections.sort(students, new Comparator<Student>() {
                @Override
                public int compare(Student o1, Student o2) {
                    return o1.ID.compareTo(o2.ID);
                }
            });
        } else if (C == 2) {
            Collections.sort(students, new Comparator<Student>() {
                @Override
                public int compare(Student o1, Student o2) {
                    if (!o1.name.equals(o2.name)) {
                        return o1.name.compareTo(o2.name);
                    }
                    return o1.ID.compareTo(o2.ID);
                }
            });
        } else {
            Collections.sort(students, new Comparator<Student>() {
                @Override
                public int compare(Student o1, Student o2) {
                    if (o1.grade != o2.grade) {
                        return o1.grade - o2.grade;
                    }
                    return o1.ID.compareTo(o2.ID);
                }
            });
        }

        for (Student s : students) {
            System.out.println(s.ID + " " + s.name + " " + s.grade);
        }


    }
}
