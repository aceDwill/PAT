import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int R = sc.nextInt();
        int G = sc.nextInt();
        int B = sc.nextInt();

        System.out.println("#" + MarsRGBTransfer(R) + MarsRGBTransfer(G) + MarsRGBTransfer(B));

    }

    static String MarsRGBTransfer(int color) {
        String dic = "0123456789ABC";
        String result = "";
        if (color == 0) {
            result = "00";
        } else {
            while (color > 0) {
                result += dic.charAt(color % 13);   // 按倒序存储结果
                color /= 13;
            }
        }
        if (result.length() == 1) {
            result = "0" + result;
        } else {
            char[] temp = {result.charAt(1),result.charAt(0)};      // 交换数位位置
            result = new String(temp);
        }
        return result;
    }
}
