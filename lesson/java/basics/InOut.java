import java.util.Scanner;
// no header file, no include statement
// javadoc used for creating header file as *.html or *.pdf

public class InOut {
    public class A {
        A () {_n = 0;}
        A (int n) {_n = n;}
        public void foo (int n) {System.out.printf("n is %d\n", n);}
        
        private int _n;
    }
    
    public static void main (String args[]) {
        // In java none of object can be created on stack
        // Each object created on heap with operator new
        // there is no operator delete instead 
        // there is a Garbage Collector and it handles all the memory issues 
        
        // Money m1; // this is a reference of Money object not a money object
        // so everthing in java handles with references thats because
        // assignment operator very efficient just copies address
        // be carefull m1 is initially null 
        
        // The object references are all initialized to null in Java. However 
        // in order to do anything useful with these references, you must set 
        // them to a valid object, else you will get NullPointerExceptions 
        // everywhere you try to use such default initialized references

        Scanner input = new Scanner(System.in);
        
        int n1, n2;

        System.out.print("Enter first integer: ");
        n1 = input.nextInt();

        System.out.print("Enter second integer: ");
        n2 = input.nextInt();

        System.out.printf("Sum is %d\n", n1 + n2);
        input.close();
    }
}
