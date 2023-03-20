import java.util.Scanner;
class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        double[] a = new double[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextDouble();
        }
        System.out.println(dem(n, a));
    }

    static int dem(int n, double[] a) {
        if (n == 0) {
            return 0;
        } else {
            if (a[n - 1] > 0) {
                return dem(n - 1, a) + 1;
            }
        }
        return dem(n - 1, a);
    }
}