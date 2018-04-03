#include <iostream>
#include <fstream>
#include <cctype>

using std::cin;
using std::cout;
using std::ifstream;
using std::endl;
using std::string;
//////////////prototypes:
bool isAlpha(char a);
bool stringIsAlpha(string inputword);
bool is_In_Dict(string inputword);
void splitOnSpace(string s, string & before, string & after);
string uppercase(string s);
string findPronunciation(string in);
int numOfPhonemes(string in);
string getNthPhoneme(string in, int n);
bool is_replace_phoneme(string originals, string s2);
bool is_add_phoneme(string s1,string s2);
bool is_remove_phoneme(string s1, string s2);
//////////////////////////////////////////////////////////////////////////
bool isAlpha(char c)//checks for characters that are not alphabetical
{
  return ((c>='a'&& c<='z') || (c>='A' && c<= 'Z') || (c == static_cast<char>(39)));//apostrophe(39) allowed
}
//////////////////////////////////////////////////////////////////////////////////////////////
string uppercase(string s)/////checks the word and converts it to uppercase if needed
{
  string l="";//empty string to fill in the uppercase version of s
  for(int i=0; i< s.length();i++)
  {
    int c=static_cast<int>(s[i]);

    if (c<='z' && c>='a')//if its lowercase...
    {
      l += static_cast<char>(c-32);//add the uppercase version to the empty string
    }
    else
    {
      l += s[i];//if its already uppercase add just add it to the empty string
    }
  }
  return l;//return the converted string
}
///////////////////////////////////////////////////////////////////////////////////////
bool stringIsAlpha(string inputword)//checks to see if a given string is alphabetical
{
  for (int i=0;i<inputword.size();i++)
  {
    if (!(isAlpha(inputword[i])))//if even ONE letter is not alphatical then the entire word is nonalphabetical
    {
      return false;
    }
  }
  return true;//if it gets to here it means the word has no nonalphabetical letters
}
/////////////////////////////////////////////////////////////////////////////////////
bool is_In_Dict(string inputword)//checks to see if the word can be found in the dictionary
{
  inputword=uppercase(inputword);
  string str;
  ifstream cmu("cmudict.0.7a.txt");//reads the file
  while (getline(cmu, str))//using getline to in order to stop reading when it reaches newline
  {
    if (str[0] == ';')//if the first character is the semi colon, start new iteration
      continue;
    string word="";
    string pronunciation="";
    splitOnSpace(str,word, pronunciation);//splits the word from its pronunciation
    if (inputword == word && stringIsAlpha(inputword))//if the inputed word is found in the dictionary AND is alphabetical...
    {
      return true;//then it can be used
    }
  }
  return false;//if its not found the function returns false.
}
/////////////////////////////////////////////////////////////////////////////////
void splitOnSpace(string s, string & before, string & after)
{//splits words on space
  // reset strings
  before = "";
  after = "";
  // accumulate before space
  int i = 0;
  while (i < s.size() && !(isspace(s[i])) )
  {
    before += s[i];
    i++;
  }
  // skip the space
  i++;
  // accumulate after space
  while (i < s.size())
  {
    after += s[i];
    i++;
  }

}
/////////////////////////////////////////////////////////////////////////////////////
string findPronunciation(string inputword)//finds the pronunciation of the inputed word
{
  inputword=uppercase(inputword);
  string str;
  ifstream cmu("cmudict.0.7a.txt");//reads the file
  while (getline(cmu, str))//using getline to in order to stop reading when it reaches newline
  {
    if (str[0] == ';')//if the first character is the semi colon, start new iteration
      continue;
    string word="";
    string pronunciation="";
    splitOnSpace(str,word, pronunciation);//splits the word from its pronunciation
      if (inputword == word)//if the inputed word is found in the dictionary...
      {
        return pronunciation;//return its pronunciation
      }
  }
}
/////////////////////////////////////////////////////////////////////////////////////////////////
int numOfPhonemes(string pronunciation)//finds the number of phonemes in a pronunciation
{
  int count=0;
  for(int i=0;i<pronunciation.size();i++)
  {
    if (isspace(pronunciation[i-1]))//every time there is a space before a character, it will increment the count
    {
      count++;
    }
  }
  return count;//the resulting count will be the number of phonemes of the word
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
string getNthPhoneme(string pronunciation, int n)//gets the desired phoneme from the pronunciation
{
  string nthPhoneme="";
  int phonum=0;
  for(int i=0;i<pronunciation.size();i++)
  {
    if (pronunciation[i]!=' ')//while the char is not a space...
    {
      nthPhoneme+=pronunciation[i];//add it to the empty string
    }
    else if (nthPhoneme!="")
    {
      if (phonum==n)//if the current phoneme matches the desired phoneme...
      {
        return nthPhoneme;//return it
      }
      nthPhoneme="";//if not then reset the string to empty and add
      phonum++;
    }
  }
}
//////////////////////////////////////////////////////////////////////////////////////////
bool is_replace_phoneme(string s1, string s2)//this function checks whether the first pronunciation
//is the same as the second one if one phoneme is replaced
{
  //get the number of phonemes(it doesnt matter which one because....
  //for replace phonemes to work..both words must have the same number of phonemes
  int phonemecount1=numOfPhonemes(s1);
  int phonemecount2=numOfPhonemes(s2);
  if (phonemecount1!=phonemecount2)
  {
    return false;
  }
  int count=0;//initialize the count
  for (int i=0;i<phonemecount1;i++)
  {
    if (getNthPhoneme(s1,i)!=getNthPhoneme(s2,i))//whenever the phonemes are the same...
    {
      count++;// increment the count
    }
  }
  if (count==1)//if only one change occured,that means the pronunciation will be the same if one phoneme is replaced
  {
    return true;
  }
  return false;
}
/////////////////////////////////////////////////////////////////////////////////
bool is_add_phoneme(string s1, string s2)
{
  int phonemecount1=numOfPhonemes(s1);
  int phonemecount2=numOfPhonemes(s2);
  if (phonemecount1!=phonemecount2-1)
  {
    return false;
  }
  int count=0;
  for (int i=0;i<phonemecount1;i++)
  {
    if (getNthPhoneme(s1,i)==getNthPhoneme(s2,i) || getNthPhoneme(s1,i)==getNthPhoneme(s2,i+1))
    {
      count++;
    }
  }
  if (count==numOfPhonemes(s1))
  {
    return true;
  }
  return false;
}
////////////////////////////////////////////////////
bool is_remove_phoneme(string s1, string s2)
{
  int phonemecount1=numOfPhonemes(s1);
  int phonemecount2=numOfPhonemes(s2);
  if (phonemecount2!=phonemecount1-1)
  {
    return false;
  }
  int count=0;
  for (int i=0;i<phonemecount2;i++)
  {
    if (getNthPhoneme(s2,i)==getNthPhoneme(s1,i) || getNthPhoneme(s2,i)==getNthPhoneme(s1,i+1))
    {
      count++;
    }
  }
  if (count==numOfPhonemes(s2))
  {
    return true;
  }
  return false;
}
//////////////Program ends