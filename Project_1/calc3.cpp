//Write an even better calculator program calc3.cpp that can understand squared numbers. We are going to use a simplified notation X^ to mean X2. For example, 10^ + 7 - 51^ should mean 102 + 7 − 512.
//
//Example:
//When reading input file formulas.txt

//5^;
//1000 + 6^ - 5^ + 1;
//the program should report:

//$ ./calc3 < formulas.txt
//25
//1012
//A hint:
//To take into account ^, don’t add or subtract new numbers right away after reading them. Instead, remember the number, read the next operator and if it is a ^, square the remembered number, then add or subtract it.

#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::cin;


int main() {
    string s;
    while(cin >> s) { // While the reading operation is a success
        cout << s << endl;  // print the read word
    }
}
