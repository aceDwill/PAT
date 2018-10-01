/*
        思路：1.先将记录按字母时间排序
              2.输出配对记录的费用
              3.输出用户总的费用
        注：测试点2，3超时
 */


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

class Record {

    String name;
    String time;
    int day;
    int hour;
    int min;
    String state;   // 表示状态在线或离线

    public Record(String name, String time, String state) {
        String[] t = time.split(":");
        this.name = name;
        this.time = time;
        this.day = Integer.parseInt(t[1]);
        this.hour = Integer.parseInt(t[2]);
        this.min = Integer.parseInt(t[3]);
        this.state = state;
    }

    // 返回一个数组，依次的值为通话一次时间和费用
    public int[] phoneBills(int onlineDay, int onlineHour, int onlineMin, int[] toll) {
        int[] result = new int[2];
        int cntTime = 0;    // 累计分钟数
        int phoneBill = 0;  // 每次通话费用

        while (onlineDay < day || onlineHour < hour || onlineMin < min) {
            cntTime++;
            phoneBill += toll[onlineHour];
            onlineMin++;
            if (onlineMin == 60) {
                onlineMin = 0;
                onlineHour += 1;
            }
            if (onlineHour == 24) {
                onlineHour = 0;
                onlineDay += 1;
            }

        }
        result[0] = cntTime;
        result[1] = phoneBill;
        return result;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] line = reader.readLine().split(" ");
        int[] toll = new int[24];
        // 将输入的各时段费用转化为整型变量
        for (int i = 0; i < 24; i++) {
            toll[i] = Integer.parseInt(line[i]);
        }
        int N = Integer.parseInt(reader.readLine());
        ArrayList<Record> records = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            line = reader.readLine().split(" ");
            Record c = new Record(line[0], line[1], line[2]);
            records.add(c);
        }
        // 对所有通话记录排序
        Collections.sort(records, new Comparator<Record>() {
            @Override
            public int compare(Record o1, Record o2) {
                // 名字不等，先按字母表顺序排序
                if (!o1.name.equals(o2.name)) {
                    return o1.name.compareTo(o2.name);
                }
                if (o1.day != o2.day) {
                    return o1.day - o2.day;
                }
                if (o1.hour != o2.hour) {
                    return o1.hour - o2.hour;
                }
                return o1.min - o2.min;
            }
        });

        boolean online = false;         // 这条记录前存不存在上线记录
        boolean hasPrinted = false;     // 有没有输出费用记录
        Record onlineRecords = null;     // 存储上一条上线记录
        float totalBill = 0;      // 每个人总的费用
        for (int i = 0; i < N; i++) {
            Record temp = records.get(i);
            // 当名字不一样表示进入下位顾客，输出上一位客户的总费用
            if (totalBill != 0 && !temp.name.equals(onlineRecords.name)) {
                System.out.printf("Total amount: $%.2f\n", totalBill);
                hasPrinted = false;
                totalBill = 0;
            }
            if (temp.state.equals("on-line")) {
                online = true;
                onlineRecords = temp;
            } else {
                // 配对成功
                if (online && temp.name.equals(onlineRecords.name)) {
                    if (!hasPrinted) {
                        System.out.println(temp.name + " " + temp.time.substring(0, 2));
                        hasPrinted = true;
                    }
                    // 计算通话时间和费用
                    int[] result = temp.phoneBills(onlineRecords.day, onlineRecords.hour,
                            onlineRecords.min, toll);
                    String onlineTime = onlineRecords.time.substring(3);
                    String offlineTime = temp.time.substring(3);
                    int phoneTime = result[0];      // 通话时间
                    float bill = (float) result[1] / 100;  // 通话费用
                    totalBill += bill;
                    System.out.printf("%s %s %d $%.2f\n", onlineTime, offlineTime,
                            phoneTime, bill);
                    online = false;
                }
            }

        }

        // 输出最后一个客户的总费用信息
        if (totalBill != 0) {
            System.out.printf("Total amount: $%.2f\n", totalBill);
        }
    }

}

