/*
	思路：1.将所有距离加起来，和为sum_all_distance
          2.将1号点到第i个点的下一个点的距离存储到distances[i]
          3.计算两个点之间的距离，即distances[end - 1] - distance[start - 1]
          4.比较sum_all_distance和3中距离，输出最小结果

		 PS：如果数组距离进行处理，每次迭代计算start到end的距离，测试点2会出现运行超时
		 PPS: java输入太慢，测试点2超时
*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main {
    public static void main(String[] args) throws IOException {

        int[] distances = new int[100010];
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] first_line = reader.readLine().split(" ");
        int sum_all_distance = 0;
        for (int i = 1; i < first_line.length; i++) {
            int temp = Integer.parseInt(first_line[i]);
            sum_all_distance += temp;
            distances[i] = sum_all_distance;
        }
        int M = Integer.parseInt(reader.readLine());
        for (int i = 0; i < M; i++) {
            String[] line = reader.readLine().split(" ");
            int start = Integer.parseInt(line[0]);
            int end = Integer.parseInt(line[1]);

            // 按地点从小到大排序
            if (start > end) {
                int temp = start;
                start = end;
                end = temp;
            }

            int result = distances[end - 1] - distances[start - 1];

            result = Math.min(result, sum_all_distance - result);
            System.out.println(result);
        }
    }
}
