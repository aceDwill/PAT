/*
        思路：用一个用户类的数组保存数据，按规则排序后输出
        注：测试点4超时
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;

class PATUser {

    String ID="";
    int[] score = {-1, -1, -1, -1, -1, -1};      // 将每题的分数初始化为-1
    int solutionCount = 0;                       // 满分题目数
    int totalScore = 0;                          // 总分
    boolean hasSubmitted = false;                // 有没有提交过

    // 输出用户相关信息
    public void printMessage(int K) {
        System.out.print(" " + ID + " " + totalScore);
        for (int i = 1; i <= K; i++) {
            if (score[i] != -1) {
                System.out.print(" " + score[i]);
            } else {
                System.out.print(" " + "-");
            }
        }
        System.out.println();
    }

}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] line = reader.readLine().split(" ");
        int N = Integer.parseInt(line[0]);
        int K = Integer.parseInt(line[1]);
        int M = Integer.parseInt(line[2]);

        line = reader.readLine().split(" ");
        int[] problemScore = new int[K + 1];        // 每题满分分数
        // 将字符串满分转化为整型满分
        for (int i = 1; i <= K; i++) {
            problemScore[i] = Integer.parseInt(line[i - 1]);
        }

        PATUser[] users = new PATUser[N + 1];   // 存储用户数组，索引0的引用为空
        // 初始化每个用户
        for (int i = 1; i <= N; i++) {
            users[i] = new PATUser();
        }
        for (int i = 0; i < M; i++) {
            line = reader.readLine().split(" ");
            int ID = Integer.parseInt(line[0]);
            int ithProblem = Integer.parseInt(line[1]);
            int score = Integer.parseInt(line[2]);
            PATUser currentUser = users[ID];
            currentUser.ID = line[0];

            // 题目没通过编译但提交过，分数更新为0
            if (score == -1 && currentUser.score[ithProblem] == -1){
                currentUser.score[ithProblem] = 0;
                continue;
            }

            // 同一个人同一个问题分数更高，更新分数
            if (score > currentUser.score[ithProblem]) {
                // 分数为满分，满分题目数+1
                if (score == problemScore[ithProblem]) {
                    currentUser.solutionCount++;
                }
                // 更新用户总分,除了初始情况每题为-1，其他情况要先减去上次得分，再加上这次更高得分
                if (currentUser.score[ithProblem] != -1) {
                    currentUser.totalScore -= currentUser.score[ithProblem];
                    currentUser.totalScore += score;
                } else {
                    currentUser.totalScore += score;
                }
                currentUser.score[ithProblem] = score;      // 更新最高得分
                currentUser.hasSubmitted = true;            // 更新提交情况
            }
        }
        Arrays.sort(users, 1, N + 1, new Comparator<PATUser>() {
            @Override
            public int compare(PATUser o1, PATUser o2) {
                if (o1.totalScore != o2.totalScore) {
                    return o2.totalScore - o1.totalScore;
                }
                if (o1.solutionCount != o2.solutionCount) {
                    return o2.solutionCount - o1.solutionCount;
                }
                return o1.ID.compareTo(o2.ID);
            }
        });

        int lastUserRank = 1;   // 上一个用户排名
        System.out.print(lastUserRank);
        users[1].printMessage(K);
        for (int i = 2; i <= N; i++) {
            if (!users[i].hasSubmitted){
                continue;
            }else {
                if (users[i].totalScore != users[i-1].totalScore){
                    lastUserRank = i;
                }
                System.out.print(lastUserRank);
                users[i].printMessage(K);
            }
        }

    }
}
