#include <iostream>
#include <string>
#include <locale>
#include "allcaps.h"

using namespace std;

/*********** AllCaps(TextProcessor *) ***********
  Purpose: Constructor of Class AllCaps
  Return: this
************************************/
AllCaps::AllCaps(TextProcessor *tp):Editor(tp) {}


/*********** setSource(istream *) ***********
  Purpose: A method of Class AllCaps
  				 set input source.
  Return: void
************************************/
void AllCaps::setSource(istream *inp){tp->setSource(inp);}


/*********** getWord() ***********
  Purpose: A method of Class AllCaps
  				 get the word and change all characters to corresponding capital letter.
  Return: string(word already changed)
************************************/
string AllCaps::getWord() {
  string s = tp->getWord();											 // get the word
  int l = s.length();														 // length of the word

  // A loop to change every character of the word to corresponding capital letter.
  for(int i = 0; i < l; i++){
  	s[i] = toupper(s[i]);
  }
  return s;																			 // return changed word
}

/*********** fail() ***********
  Purpose: A method of Class AllCaps
  				 whether reading input is failed
  Return: true if reading input is failed, otherwise false.
************************************/
bool AllCaps::fail() const { return tp->fail(); }

