//Write a better version of the calculator, calc2.cpp, that can evaluate multiple arithmetic expressions. Let’s use the semicolon symbol that must be used at the end of each expression in the input.

//Assuming that the input file formulas.txt looks as follows:

//15 ;
//10 + 3 + 0 + 25 ;
//5 + 6 - 7 - 8 + 9 + 10 - 11 ;
//When we run the program with that input, the output should evaluate all of the expressions and print them each on its own line:
//
//$ ./calc2 < formulas.txt
//15
//38
//4

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
cin>>sum;
while(cin >> symbols >> numbers )
  {
   if (symbols == '+')
   {
     sum+=numbers;
   }
   else if (symbols == '-')
   {
    sum-=numbers;
   }
   else if (symbols == ';')
   {
     cout<<sum<<endl;
     sum=numbers;
   }
  }
  cout<<sum<<endl;
}
