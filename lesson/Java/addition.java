import java.util.Scanner;
// no header file, no include statement
// javadoc use for creating header file as *.html or *.pdf

public class addition {
    public static void main (String args[]) {
        //! In java any object cannot be created on stack
        //! Each object created on heap with operator new
        //! there is no operator delete
        //! there is a Garbage Collector and it handles all the memory issues 
        //! Money m1; // this is a reference
        Scanner input = new Scanner(System.in);

        int n1, n2;

        System.out.print("Enter first integer: ");
        n1 = input.nextInt();

        System.out.print("Enter second integer: ");
        n2 = input.nextInt();

        System.out.printf("Sum is %d\n", n1 + n2);
    }
}
