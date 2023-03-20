import java.util.Scanner;
class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            int n = sc.nextInt();
            System.out.println(X(n) + " " + Y(n));
        }
    }

    static int X(int n) {
        if (n == 0) {
            return 1;
        } else {
            return X(n - 1) + Y(n - 1);
        }
    }

    static int Y(int n) {
        if (n == 0) {
            return 0;
        } else {
            return 3 * X(n - 1) + Y(n - 1);
        }
    }

}
