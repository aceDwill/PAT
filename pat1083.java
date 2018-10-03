import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

class Student {

    String name;
    String ID;
    int grade;

    public Student(String name, String ID, String grade) {
        this.name = name;
        this.ID = ID;
        this.grade = Integer.parseInt(grade);
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(reader.readLine());

        ArrayList<Student> students = new ArrayList<>();
        ArrayList<Student> validStudents = new ArrayList<>();   // 有效学生集合

        String[] line;
        for (int i = 0; i < N; i++) {
            line = reader.readLine().split(" ");
            Student s = new Student(line[0], line[1], line[2]);
            students.add(s);
        }
        line = reader.readLine().split(" ");
        int grade1 = Integer.parseInt(line[0]);
        int grade2 = Integer.parseInt(line[1]);
        for (int i = 0; i < N; i++) {
            Student temp = students.get(i);
            if (temp.grade >= grade1 && temp.grade <= grade2) {
                validStudents.add(temp);
            }
        }
        if (!validStudents.isEmpty()) {
            Collections.sort(validStudents, new Comparator<Student>() {
                @Override
                public int compare(Student o1, Student o2) {
                    return o2.grade - o1.grade;
                }
            });
            for (Student s : validStudents) {
                System.out.println(s.name + " " + s.ID);
            }
        }else {
            System.out.println("NONE");
        }
    }
}
