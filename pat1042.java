/*
        思路：用两个数组，一个数组存储初始牌序，另一个存储洗牌一次后的牌序，然后迭代
 */


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {

        int[] cards = new int[55];    //初始化的排序
        int[] cards_result = new int[55];     //最后结果的牌序
        String[] cards_color = {"S", "H", "C", "D", "J"}; //牌的花色

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int K = Integer.parseInt(reader.readLine());    //记录洗牌次数
        int[] order = new int[55];      //  记录洗牌次序
        String[] str_order = reader.readLine().split(" ");
        for (int i = 1; i <= 54; i++) {
            order[i] = Integer.parseInt(str_order[i - 1]);
        }

        //初始牌序
        for (int i = 1; i < 55; i++) {
            cards[i] = i;
        }

        for (int i = 0; i < K; i++) {
            for (int j = 1; j < 55; j++) {
                cards_result[order[j]] = cards[j];
            }
            //对洗牌一次后牌序进行保存
            for (int k = 1; k < 55; k++) {
                cards[k] = cards_result[k];
            }

        }

        for (int i = 1; i < 55; i++) {
            int current_num = cards_result[i] - 1;
            System.out.print(cards_color[current_num / 13] + (current_num % 13 + 1));
            if (i != 54) {
                System.out.print(" ");
            }
        }


    }
}

