#include <iostream>
#include <string>
#include <sstream>
#include "count.h"

using namespace std;

/*********** Count(TextProcessor *, int) ***********
  Purpose: Constructor of Class Count
  Return: this
************************************/
Count::Count(TextProcessor *tp, char n): Editor(tp), n(n), record(0) {}


/*********** setSource(istream *) ***********
  Purpose: A method of Class Count
           set input source.
  Return: void
************************************/
void Count::setSource(istream *inp) {tp->setSource(inp);}


/*********** getWord() ***********
  Purpose: A method of Class Count
           get the word and count and change certain character to the number count.
  Return: string(word already changed)
************************************/
string Count::getWord() {
  string s = tp->getWord();                      // get the word
  string s1;
  string s2;
  int i = record + 1;
  unsigned int pos = s.find_first_of(n);         // first pos of n
  int finding = s.find_first_of(n);

  // A loop to deal with the n found in s
  while(finding != -1){
    if(pos == 0) {                               // is n the first of all?
      s1 = "";
    } else {
      s1 = s.substr(0, pos);
    } // if
  	if(pos == s.length() - 1) {                  // is n the last character?
      s2 = "";
    } else {
      s2 = s.substr(pos + 1);
    } // if

    // split the word replace n with the number of n we count
    ostringstream ss;
    ss << i;
  	s = s1 + ss.str() + s2;
  	i++;

    //pos of first n in s2 + length of the replace numbers + current pos
    pos = s2.find_first_of(n)+ss.str().length()+pos;
    finding = s2.find_first_of(n);
  } // while
  record = i - 1;

  return s;                                      // return the word changed
}


/*********** fail() ***********
  Purpose: A method of Class Count
           whether reading input is failed
  Return: true if reading input is failed, otherwise false.
************************************/
bool Count::fail() const { return tp->fail(); }

