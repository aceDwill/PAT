/*
      思路：在归并排序过程中判断是否与排过序的序列相等
            如果存在相等序列则是归并排序，否则为插入排序
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(reader.readLine());
        String[] line = reader.readLine().split(" ");
        int[] initSeq = new int[n];
        int[] partiallySortedSeq = new int[n];
        for (int i = 0; i < n; i++) {
            initSeq[i] = Integer.parseInt(line[i]);
        }
        line = reader.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            partiallySortedSeq[i] = Integer.parseInt(line[i]);
        }
        Solution solution = new Solution(n, initSeq, partiallySortedSeq);
        if (solution.mergeSort()) {
            System.out.println("Merge Sort");
            solution.printArr(solution.initSeq);
        } else {
            System.out.println("Insertion Sort");
            solution.insertSort();
            solution.printArr(solution.partiallySortedSeq);
        }
    }

}

class Solution {
    int n;
    int[] initSeq;
    int[] partiallySortedSeq;

    public Solution(int n, int[] initSeq, int[] partiallySortedSeq) {
        this.n = n;
        this.initSeq = initSeq;
        this.partiallySortedSeq = partiallySortedSeq;
    }

    public boolean mergeSort() {
        boolean isMergeSort = false;
        for (int i = 2; i < 2 * n; i *= 2) {
            if (Arrays.equals(initSeq, partiallySortedSeq) && i != 2) {
                isMergeSort = true;
            }
            for (int j = 0; j < n; j += i) {
                Arrays.sort(initSeq, j, Math.min(n, j + i));
            }
            if (isMergeSort) {
                return true;
            }
        }
        return false;
    }

    public void insertSort() {
        // 一段序列有序，表示没有插入过数
        boolean hasInserted = false;
        for (int i = 1; i < n; i++) {
            int temp = partiallySortedSeq[i];
            int j = i;
            while (j > 0 && temp < partiallySortedSeq[j - 1]) {
                partiallySortedSeq[j] = partiallySortedSeq[j - 1];
                hasInserted = true;
                j--;
            }
            partiallySortedSeq[j] = temp;
            if (hasInserted) {
                break;
            }
        }
    }

    public void printArr(int[] arr) {
        System.out.print(arr[0]);
        for (int i = 1; i < arr.length; i++) {
            System.out.print(" " + arr[i]);
        }
    }

}

