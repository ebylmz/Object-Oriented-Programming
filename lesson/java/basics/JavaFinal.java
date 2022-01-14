public class JavaFinal {
    static final double PI = 3.141592653589793;
    final int THRESHOLD;
    // final variable to create constant variable
    // When a variable is declared with final keyword, 
    // its value can’t be modified, essentially, a constant.
    // This also means that you must initialize a final variable.
    // If the final variable is a reference, this means that the
    // variable cannot be re-bound to reference another object,
    // but the internal state of the object pointed by that 
    // reference variable can be changed i.e. you can add 
    // or remove elements from the final array or final collection.
    
    JavaFinal () {
        // final variables must be initialized
        // either decleration time or in constructor
        // because it's value must be known at compiler time
        THRESHOLD = 16;
    }

    public static void main (String[] args) {
        final StringBuilder sb = new StringBuilder("Emirkan");
        System.out.println(sb);

        sb.append("Burak");
        System.out.println(sb);
    }
}