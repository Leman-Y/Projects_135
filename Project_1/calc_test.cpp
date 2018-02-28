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
    int numbers;
    string symbols;
    int sum=0;
    int difference=0;
    int total=0;
    int i=0;
    int num[100]={0};
    string operators[100]={""};
    while(cin >> numbers >> symbols)
    {
      num[i]=numbers;
      operators[i]=symbols;
      i++;
    }
    int size=i;
    for (int i=0;i<size;i++)
    {
      cout<<num[i]<<endl;
      cout<<operators[i]<<endl;
    }
    // for (int i=0; i<size;i++)
    // {
    //   if (i==0)
    //   {
    //     sum+=num[0];
    //   }
    //   else if (operators[i] == "+")
    //   {
    //     sum+=num[i];
    //     cout<<sum<<endl;
    //   }
    //   else if (operators[i] == "-")
    //   {
    //     difference-=num[i];//difference by value of number in numbers
    //   }
    //   total=sum+difference;
    // }
    // cout<<total<<endl;
  return 0;
}
