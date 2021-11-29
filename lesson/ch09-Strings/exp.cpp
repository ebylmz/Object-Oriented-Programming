#include <iostream>
#include <string>

using namespace std;

int main (void) {
    // Two ways of getting whole line
    string str_line, str_s;
    getline(cin, str_line);         // deliminater is '\n' by default
    getline(cin, str_line, '?');    // deliminater is '?' 

    // istream& getline(istream& ins, string& strVar, char delimiter);
    // istream& getline(istream& ins, string& strVar);
    getline(cin, str_line) >> str_s;

    const int LINE_SIZE = 80;
    char Cstr_line[LINE_SIZE];
    cin.getline(Cstr_line, LINE_SIZE);

    // sometimes new line charachter cause unexpected result to handle it
    cin.ignore(1000, '\n');

    str_line.empty(); // Returns boolean value
    // str.substr(position, length);
    // str.find(str1, pos)

    return 0;    
}