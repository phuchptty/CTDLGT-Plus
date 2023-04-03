import java.util.Scanner;

class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        System.out.println(giaTri(n, a));
    }

    static int giaTri(int n, int[] a) {
        if (n == 0) {
            return 0;
        } else {
            if (a[n - 1] % 2 == 0) {
                return giaTri(n - 1, a) + a[n - 1];
            }
        }
        return giaTri(n-1, a);
    }
}