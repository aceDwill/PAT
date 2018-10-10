/*
        attention: test case 1,2,4 Time Limit Exceeded sometimes
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

class MoonCake {

    float inventory;
    float price;
    float unitPrice;

    public MoonCake(String inventory, String price) {
        this.inventory = Float.parseFloat(inventory);
        this.price = Float.parseFloat(price);
        this.unitPrice = this.price / this.inventory;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] line = reader.readLine().split(" ");
        int N = Integer.parseInt(line[0]);      // the number of different kinds of moon cakes
        int D = Integer.parseInt(line[1]);      // the maximum total demand of the market


        String[] inventories = reader.readLine().split(" ");
        String[] prices = reader.readLine().split(" ");

        List<MoonCake> moonCakes = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            MoonCake mc = new MoonCake(inventories[i], prices[i]);
            moonCakes.add(mc);
        }

        // sort moon cakes according to their unit price in no-increasing order
        Collections.sort(moonCakes, new Comparator<MoonCake>() {
            @Override
            public int compare(MoonCake o1, MoonCake o2) {
                if (o1.unitPrice > o2.unitPrice) {
                    return -1;
                }
                return 1;
            }
        });

        float profits = 0;
        for (int i = 0; i < N; i++) {
            MoonCake temp = moonCakes.get(i);
            if (temp.inventory >= D) {
                profits += D * temp.unitPrice;
                break;
            } else {
                profits += temp.price;
                D -= temp.inventory;
            }
        }

        System.out.printf("%.2f", profits);


    }
}
