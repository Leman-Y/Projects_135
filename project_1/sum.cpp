
#include <iostream>

using std::cin; // needed in order for the program  to read the text
using std::cout;
using std::endl;
using std::string; // listing all the standards necessary for the code

int main() // this program reads a text file and finds the sum of the numbers there
{
	int number;           // must be int in order to add the numbers
	int sum = 0;          // initilized sum to avoid adding uneccessary numbers.
	while (cin >> number) // loops through the numbers
	{
		sum += number; // adds the numbers together
	}
	cout << sum << endl; // prints the sum
	return 0;
}

// by compiling the file and then executing it with < numbers.txt all
// the numbers on the text file are added up
