#include <iostream>
#include <string>
#include <sstream>
#include "doublewords.h"

using namespace std;

/*********** DoubleWords(TextProcessor *) ***********
  Purpose: Constructor of Class DoubleWords
  Return: this
************************************/
DoubleWords::DoubleWords(TextProcessor *tp): Editor(tp) {}


/*********** setSource(istream *) ***********
  Purpose: A method of Class DoubleWords
  				 set input source.
  Return: void
************************************/
void DoubleWords::setSource(istream *inp){tp->setSource(inp);}


/*********** getWord() ***********
  Purpose: A method of Class DoubleWords
  				 get the word and double the word
  Return: string(word already changed)
************************************/
string DoubleWords::getWord() {
  string s = tp->getWord();											 // get the word

  // use istringstream to avoid mutiple different words in s which are separated by space
  istringstream iss(s);
  s = "";
  string temp;

  // A loop to double every word in iss which are separated by space
  while(iss >> temp){
  	s = s + temp + " " + temp + " ";
  }
  s = s.substr(0, s.length() - 1);							 // drop the space at the end
  return s;																			 // return the word changed
}


/*********** fail() ***********
  Purpose: A method of Class DoubleWords
  				 whether reading input is failed
  Return: true if reading input is failed, otherwise false.
************************************/
bool DoubleWords::fail() const { return tp->fail(); }

