//! since Java is pure OOP language, there is no global function
//! so main function always be in the class whose name is same as file name
//! then JVM can call main function exactly filename.main()
public class hello {
    public static void main (String[] args) {
        // main must be static function to call main function
        // without creating object of it's class
        System.out.printf("Hello, %s", "World");
    }
}