
//Specifically, write a program calc.cpp that reads from the cin a sequence of one or more non-negative integers written to be added or subtracted. Space characters can be anywhere in the input. After the input ends (end-of-file is reached), the program should compute and print the result of the input summation.
//100 + 50 - 25 + 0 + 123 - 1
//Possible input for your program may look like this:
//15

//10 + 3 + 0 + 25

//1 + 1 + 1 + 1 +
//1 + 1 + 1 + 1 +
//1 + 1 + 1 + 1 +
//1 + 1 + 1 + 1
//(Each of the inputs above is a separate file containing one single formula, even if it spans multiple lines.)
//The corresponding outputs should be: 15, 38, 4, and 16.



#include <iostream>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;
using std::string;
using std::cout;
using std::endl;
using std::cin;


int main()
{
    string s;
    int sum=0;
    int difference=0;
    int total=0;
    int temp=0;
    int i=0;
    int numbers[100]={0};
    string symbols[100]={""};
    string myData[100]={""};
    while(cin >> s)
    {
      myData[i]+=s;
      i++;
    }
    int string_length=i;
    for (int i=0; i<=(string_length)/2;i++)
    {
      temp=atoi(myData[2*i].c_str());
      numbers[i]=temp;
    }
    for (int i=0;i<(string_length)/2;i++)
    {
      symbols[i+1]+=myData[2*i+1];
    }
    for (int i=0;i<=(string_length)/2;i++)
    {
      if (i==0)
      {
        sum+=numbers[0];
      }
     else if (symbols[i]=="+")
      {
        sum+=numbers[i];
      }
     else if (symbols[i]=="-")
      {
        difference-=numbers[i];//difference by value of number in numbers
      }
      total=sum+difference;
    }
     cout<<total<<endl;
}
