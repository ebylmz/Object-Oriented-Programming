import java.util.Scanner;

public class a {
    public static void main (String[] args) {
        Scanner in = new Scanner(System.in);
        int n1, n2, sum;

        do {
            System.out.printf("Enter n1: ");
            n1 = in.nextInt();
            System.out.printf("Enter n2: ");
            n2 = in.nextInt();
            System.out.printf("Sum: %d\n", n1 + n2);
        } while (n1 == 0 && n2 == 0);
    }
}