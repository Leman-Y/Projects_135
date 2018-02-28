//Specifically, write a program calc.cpp that reads from the cin a sequence of one or more non-negative integers written to be added or subtracted. Space characters can be anywhere in the input. After the input ends (end-of-file is reached), the program should compute and print the result of the input summation.
//100 + 50 - 25 + 0 + 123 - 1
//Possible input for your program may look like this:
//15
//10 + 3 + 0 + 25
//5+6- 7 -8 + 9  + 10 -   11
//1 + 1 + 1 + 1 +
//1 + 1 + 1 + 1 +
//1 + 1 + 1 + 1 +
//1 + 1 + 1 + 1
//(Each of the inputs above is a separate file containing one single formula, even if it spans multiple lines.)
//The corresponding outputs should be: 15, 38, 4, and 16.



#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::cin;


int main()
{
    int numbers;
    char symbols;
    int sum=0;
    int difference=0;
    int total=0;
    cin>>sum;
    while(cin >> symbols >> numbers)
     {
       if (symbols == '+')
       {
         sum+=numbers;
       }
       else if (symbols == '-')
       {
         difference-=numbers;
       }
     }
     total=sum+difference;
     cout<<total<<endl;

  return 0;
}
