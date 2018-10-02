/*
        思路：1.按要求将所有富豪进行排序
              2.对富豪进行预处理：对某个年龄资产在100以后的人进行舍去
              3.对具体查询进行输出
        注：测试点1，2出现超时
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

class RichMan {

    String name;
    int age;
    int netWorth;

    public RichMan(String name, String age, String netWorth) {
        this.name = name;
        this.age = Integer.parseInt(age);
        this.netWorth = Integer.parseInt(netWorth);
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] line = reader.readLine().split(" ");
        int N = Integer.parseInt(line[0]);
        int K = Integer.parseInt(line[1]);

        ArrayList<RichMan> richMEN = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            line = reader.readLine().split(" ");
            RichMan richMan = new RichMan(line[0], line[1], line[2]);
            richMEN.add(richMan);
        }

        Collections.sort(richMEN, new Comparator<RichMan>() {
            @Override
            public int compare(RichMan o1, RichMan o2) {
                if (o1.netWorth != o2.netWorth) {
                    return o2.netWorth - o1.netWorth;
                }
                if (o1.age != o2.age) {
                    return o1.age - o2.age;
                }
                return o1.name.compareTo(o2.name);
            }
        });

        int[] age = new int[1000];      // 某个年龄的人数
        ArrayList<RichMan> validRichMen = new ArrayList<>();    // 某年龄人数在100以后的就不用统计了

        for (int i = 0; i < N; i++) {
            RichMan temp = richMEN.get(i);
            if (age[temp.age] < 100) {
                age[temp.age]++;
                validRichMen.add(temp);
            }
        }

        for (int i = 1; i <= K; i++) {
            line = reader.readLine().split(" ");
            int M = Integer.parseInt(line[0]);
            int Amin = Integer.parseInt(line[1]);
            int Amax = Integer.parseInt(line[2]);
            System.out.println("Case #" + i + ":");
            int printNum = 0;
            for (int j = 0; j < validRichMen.size() && printNum < M; j++) {
                RichMan temp = validRichMen.get(j);
                if (temp.age >= Amin && temp.age <= Amax) {
                    System.out.println(temp.name + " " + temp.age + " " + temp.netWorth);
                    printNum++;
                }
            }

            if (printNum == 0) {
                System.out.printf("None");
            }

        }

    }
}
