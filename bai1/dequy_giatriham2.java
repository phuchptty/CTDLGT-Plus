import java.util.Scanner;
class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            int n = sc.nextInt();
            System.out.printf("%.10f\n", giaTri(1, n));
        }
    }

    static double giaTri(int i, int n) {
        if (i == n) {
            return Math.sqrt(n);
        } else {
            return Math.sqrt(i + giaTri(i + 1, n));
        }
    }

}