#include <iostream>
#include <fstream>
#include <cctype>

using std::cin;
using std::cout;
using std::ifstream;
using std::endl;
using std::string;

bool isAlpha(char a);
bool stringIsAlpha(string inputword);
bool is_In_Dict(string inputword);
void splitOnSpace(string s, string & before, string & after);
string uppercase(string s);
string findPronunciation(string in);
int numOfPhonemes(string in);
string getNthPhoneme(string in, int n);
bool is_add_phoneme(string s1,string s2);
bool is_remove_phoneme(string s1, string s2);
bool is_replace_phoneme(string originals, string s2);
