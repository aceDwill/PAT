import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Account {
    String name;
    String pwd;

    public Account(String name, String pwd) {
        this.name = name;
        this.pwd = pwd;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        Account[] accounts = new Account[1010];    // 记录修改账号数组
        int numOfModified = 0;    // 记录修改账号数
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(reader.readLine());
        for (int i = 0; i < N; i++) {
            boolean isModified = false;
            String[] line = reader.readLine().split(" ");
            StringBuilder sb = new StringBuilder(line[1]);
            // 按要求进行替换字符
            for (int j = 0; j < sb.length(); j++) {
                switch (sb.charAt(j)) {
                    case '1':
                        sb.setCharAt(j, '@');
                        isModified = true;
                        break;
                    case '0':
                        sb.setCharAt(j, '%');
                        isModified = true;
                        break;
                    case 'l':
                        sb.setCharAt(j, 'L');
                        isModified = true;
                        break;
                    case 'O':
                        sb.setCharAt(j, 'o');
                        isModified = true;
                        break;
                    default:
                        break;

                }
            }
            if (isModified) {
                accounts[numOfModified] = new Account(line[0], sb.toString());
                numOfModified += 1;
            }
        }
        // 没有账号被修改
        if (numOfModified == 0) {
            // 注意输出语句单复数情况
            if (N == 1) {
                System.out.println("There is 1 account and no account is modified");
            } else {
                System.out.println("There are " + N + " accounts and no account is modified");
            }
        } else {
            System.out.println(numOfModified);
            for (int i = 0; i < numOfModified; i++) {
                System.out.println(accounts[i].name + " " + accounts[i].pwd);
            }
        }

    }
}
