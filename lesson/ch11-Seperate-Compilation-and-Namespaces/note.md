# Compilation Unit
* A file, along with all files #included in file

* Every Compilation unşt has unnamed namespace, with this all names are than local to compilation unit.
  (https://youtu.be/eu-FKkiNnTM?list=PLuid2q5iknODFPHJPoO0gE1aWL9LGnqZ1&t=2533)

* Use unnamed namespace to keep things "local". It's not possible to use an unnamed namespace outside of the compilation unit.

* Every time you make a compiler call, you are creating a new compilation unit

# Namespace
What is the purpose of using namespace?

* All code goes in some namespace. Unless specified all the definition in global namespace. For example main() function is in global namespace.

* No need for using directive (implied "automatic" using directive)

* Global namespace is always available

* Namespaces can be defined seperate files for exp i define part of my namespace in interface file (header) and i define part of it in implementation file.

* Namespaces should be unique like your last name, institiuon name...

* using decleration
    using std::cout; // like variable decleration
 using directive
    using namespace std;
 without using directve:
    NS1::fun1();

* Main function must be in global namespace. Otherwise program will be compile but not linked. Because main function needed and linker calls just main not like NS1::main.    
