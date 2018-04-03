#include <iostream>
#include <fstream>
#include <cctype>
#include "header_project2.h"

using std::cin;
using std::cout;
using std::ifstream;
using std::endl;
using std::string;

int main()
{
  string inputword;
  while(inputword!="dict")
  {
    cout<<"Please enter a word to be searched in the dictionary, type dict to stop."<<endl;
    cin >> inputword;//allows user input
    string upword=uppercase(inputword);//converts inputed word to uppercase if needed
    if (is_In_Dict(upword))
    {
      string inputwordpro=findPronunciation(upword);
      string identicalwords="";
      string addwords="";
      string removewords="";
      string replacewords="";
      int inputphocount=numOfPhonemes(inputwordpro);
      string str;
      string word="";
      string pronunciation="";
      ifstream cmu("cmudict.0.7a.txt");//reads the file
      while (getline(cmu, str))//using getline to in order to stop reading when it reaches newline
      {
        if (str[0] == ';')//if the first character is the semi colon, start new iteration
          continue;
        splitOnSpace(str,word, pronunciation);//splits the word from its pronunciation
        int phonemecount=numOfPhonemes(pronunciation);
        if (inputwordpro==pronunciation && word!=upword)
        {
          identicalwords+=word+" ";
        }
        if (is_add_phoneme(inputwordpro,pronunciation) && stringIsAlpha(word))
        {
          addwords+=word+" ";
        }
        if (is_remove_phoneme(inputwordpro,pronunciation) && stringIsAlpha(word))
        {
          removewords+=word+" ";
        }
        if (is_replace_phoneme(inputwordpro,pronunciation) && stringIsAlpha(word))
        {
          replacewords+=word+" ";
        }
      }
      cout << "Pronounciation   : " << inputwordpro << "\n";
	    cout << "Identical        : " << identicalwords << "\n";
	    cout << "Add Phoneme      : " << addwords << "\n";
	    cout << "Remove Phoneme   : " << removewords << "\n";
	    cout << "Replace Phoneme  : " << replacewords << "\n";
  }
  else
  {
    cout<<"Not Found"<<endl;
  }
}
}
