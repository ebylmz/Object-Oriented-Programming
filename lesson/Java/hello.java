// since Java is pure OOP language, there is no global function
// so main function always be in the class whose name is same as file name
// then JVM can call main function exactly filename.main()
public class hello {
    public static void main (String[] args) {
        // main is a static function to be able to
        // call without creating object of it
        System.out.printf("Hello, %s", "World");
    }
}