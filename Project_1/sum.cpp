
#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::cin;

int main() //this program reads a text file and finds the sum of the numbers there
{
  int number;
  int sum=0;
  while(cin >> number)
  {
    sum+=number;//adds the numbers together
  }
  cout<<sum<<endl;//prints the sum
  return 0;
}
