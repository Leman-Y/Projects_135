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
