#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// read symbol
// if symbol is carrot, then do math (have variable to save last number added/subtracted, which
// means last operation should also be stored) then, if was carrot, go back to top of loop once
// determined that its a +/_, then read the number, store both in memoory, and do proper operation
// check for ^, if present, subtract previous number (need var to store), square and add back to sum

// store previous operation

int main() {
	int numbers;
	char symbols;
	char old_op = '+';     // assume the first number is always positive
	int total = 0;         // initialize the total
	cin >> numbers;        // read in the first number
	while (cin >> symbols) // read in the symbol after the number
	{
		if (symbols == '^') // if the symbol is a carrot...
		{
			numbers = numbers * numbers; // square the number
			cin >> symbols;              // read in the symbol next to it
		}
		if (old_op == '-') // if the symbol before the number is -...
		{
			total -= numbers; // subtract from total
		}
		if (old_op == '+') // if the symbol before the number is +.....
		{
			total += numbers; // add to the total
		}
		old_op = symbols;  // the old operator is equal to the the new
		cin >> numbers;    // next number is read
		if (old_op == ';') // if the next symbol is a ;...
		{
			cout << total << endl; // Then the total is printed
			total = 0;             // total is then reinitialized
			old_op = '+'; // the first operator is reinitialized back to plus with the assumtion
			              // that the number in the next row will always be positive
		}
	}
	return 0;
}
