/*
        solution: 1.sort applicants according to their final grade and grade of ge
                  2.create list of admission result,if someone meets the conditions,put him in
                  3.print applicants' id who are being admitted
        attention: test case 4 Time Limit Exceeded
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;

class Applicant {

    int id;
    int ge;
    int gi;
    int finalGrade;
    int[] choices;

    public Applicant(int id, int ge, int gi, int[] choices) {
        this.id = id;
        this.ge = ge;
        this.gi = gi;
        finalGrade = ge + gi;
        this.choices = choices;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] line = reader.readLine().split(" ");
        int N = Integer.parseInt(line[0]);   // number of applicants
        int M = Integer.parseInt(line[1]);   // number of schools
        int K = Integer.parseInt(line[2]);   // number of choices

        int[] schoolQuota = new int[M];     // quota in a certain school
        line = reader.readLine().split(" ");
        // quota in String to int
        for (int i = 0; i < M; i++) {
            schoolQuota[i] = Integer.parseInt(line[i]);
        }

        int[] line_int;     // to save applicants data in integer
        int len = K + 2;    // number of integers in a line
        ArrayList<Applicant> applicants = new ArrayList<>();    // to save all applicants

        for (int i = 0; i < N; i++) {
            line = reader.readLine().split(" ");
            line_int = new int[len];
            // String to int
            for (int j = 0; j < len; j++) {
                line_int[j] = Integer.parseInt(line[j]);
            }
            int[] choices = Arrays.copyOfRange(line_int, 2, len);
            Applicant applicant = new Applicant(i, line_int[0], line_int[1], choices);
            applicants.add(applicant);
        }

        // sort applicants according to their final grade and grade of ge
        Collections.sort(applicants, new Comparator<Applicant>() {
            @Override
            public int compare(Applicant o1, Applicant o2) {
                if (o1.finalGrade != o2.finalGrade) {
                    return o2.finalGrade - o1.finalGrade;
                }
                return o2.ge - o1.ge;
            }
        });

        // to save final admission result
        ArrayList<ArrayList<Applicant>> admissionResult = new ArrayList<>();

        // init of admission result
        for (int i = 0; i < M; i++) {
            ArrayList<Applicant> certainSchoolResult = new ArrayList<>();
            admissionResult.add(certainSchoolResult);
        }


        for (int i = 0; i < N; i++) {
            Applicant temp = applicants.get(i);
            for (int choice : temp.choices) {
                if (schoolQuota[choice] > 0) {
                    schoolQuota[choice]--;
                    admissionResult.get(choice).add(temp);
                    break;
                }
                if (schoolQuota[choice] == 0) {
                    ArrayList<Applicant> schoolResult = admissionResult.get(choice);
                    int num = schoolResult.size();      // number of  applicants being admitted
                    if (num != 0) {
                        // if someone's final grade and grade of ge both equal last applicant's
                        // he should be admitted to the same school too even there is no quota
                        if (temp.finalGrade == schoolResult.get(num - 1).finalGrade
                                && temp.ge == schoolResult.get(num - 1).ge) {
                            admissionResult.get(choice).add(temp);
                        }
                    }
                }
            }
        }

        for (int i = 0; i < M; i++) {
            if (!admissionResult.get(i).isEmpty()) {
                // sort a certain school's applicants being admitted according to their ID
                Collections.sort(admissionResult.get(i), new Comparator<Applicant>() {
                    @Override
                    public int compare(Applicant o1, Applicant o2) {
                        return o1.id - o2.id;
                    }
                });
                // print applicants' ID
                for (int j = 0; j < admissionResult.get(i).size(); j++) {
                    System.out.print(admissionResult.get(i).get(j).id);
                    if (j == admissionResult.get(i).size() - 1){
                        System.out.println();
                        break;
                    }
                    System.out.print(" ");
                }
            }else {
                System.out.println();
            }
        }
    }
}
