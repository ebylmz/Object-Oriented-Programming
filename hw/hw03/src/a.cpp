#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void readMovement (string s) {
    stringstream sstream(s);
    char letter, seperator;
    int i1, i2;

    // A0-12 A-9
    sstream >> letter >> i1 >> seperator >> i2;
}

int main (void) {
    string s;
    cout << "Movement: ";
    cin >> s;

    //movement A1-1
    stringstream ss(s);
    char c1, c2;
    int i;
    ss >> c1 >> i;
    cout << c1 << " " << i << endl;   
}