#include <iostream>

using std::cout;
using std::endl;

template<class T>
void swap (T & var1, T & var2);

template<class T>
void printPairs (T & var1, T & var2);


int main () {
    int a = 5, b = 17;

    printPairs(a, b);
    cout << " swap ";
    swap(a, b);
    printPairs(a, b);

    cout << endl;

    char c = 'E', d = 'B';
    printPairs(c, d);
    cout << " swap ";
    swap(c, d);
    printPairs(c, d);
}

template<class T>
void swap (T & var1, T & var2) {
    T temp = var1;
    var1 = var2;
    var2 = temp;
}

template<class T>
void printPairs (T & var1, T & var2) {
    cout << "(" << var1 << ", " << var2 << ")"; 
}