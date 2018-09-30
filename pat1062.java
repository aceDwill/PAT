/*
    思路：1.先将输入成绩按要求添加到sages,noblemen,foolmen,smallmen集合中,并添加到men中
          2.对四种人分别进行排序，按照s,n,f,s依次输出四种人的成绩
          注：2，3，4测试点运行超时
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;


class Man {
    String ID_Number;
    int virtueGrade;
    int talentGrade;

}

class ManComp implements Comparator<Man> {

    @Override
    public int compare(Man o1, Man o2) {
        int totalGrade1 = o1.talentGrade + o1.virtueGrade;
        int totalGrade2 = o2.talentGrade + o2.virtueGrade;
        if (totalGrade1 != totalGrade2) {
            // 总分不一样，按总分从大到小排序
            return totalGrade2 - totalGrade1;
        } else if (o1.virtueGrade != o2.virtueGrade) {
            // 总分一样，virtual不一样，按virtual从大到小排序
            return o2.virtueGrade - o1.virtueGrade;
        } else {
            // 总分及virtual一样，按ID由小到大排序
            return o1.ID_Number.compareTo(o2.ID_Number);
        }
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] line = reader.readLine().split(" ");
        int N = Integer.parseInt(line[0]);
        int L = Integer.parseInt(line[1]);
        int H = Integer.parseInt(line[2]);
        ArrayList<ArrayList<Man>> men = new ArrayList<>();     // 按索引依次为圣人，君子，愚人，小人的集合
        ArrayList<Man> sages = new ArrayList<>();
        men.add(sages);
        ArrayList<Man> noblemen = new ArrayList<>();
        men.add(noblemen);
        ArrayList<Man> foolmen = new ArrayList<>();
        men.add(foolmen);
        ArrayList<Man> smallmen = new ArrayList<>();
        men.add(smallmen);

        int M = 0;  // 记录实际排序人数

        for (int i = 0; i < N; i++) {
            line = reader.readLine().split(" ");
            int vGrade = Integer.parseInt(line[1]);
            int tGrade = Integer.parseInt(line[2]);
            Man man = new Man();
            man.ID_Number = line[0];
            man.virtueGrade = vGrade;
            man.talentGrade = tGrade;
            if (vGrade >= H && tGrade >= H) {
                sages.add(man);
                M++;
            } else if (vGrade >= H && tGrade >= L) {
                noblemen.add(man);
                M++;
            } else if (tGrade >= L && vGrade >= tGrade) {
                foolmen.add(man);
                M++;
            } else if (vGrade >= L && tGrade >= L) {
                smallmen.add(man);
                M++;
            }

        }

        System.out.println(M);
        for (int i = 0; i < men.size(); i++) {
            Collections.sort(men.get(i), new ManComp());
            for (Man temp : men.get(i)) {
                System.out.println(temp.ID_Number + " " + temp.virtueGrade + " " + temp.talentGrade);
            }
        }
    }
}
