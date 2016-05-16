#include <iostream>
#include <string>
#include <sstream>
#include "dropfirst.h"

using namespace std;

/*********** DropFirst(TextProcessor *, unsigned int) ***********
  Purpose: Constructor of Class DropFirst
  Return: this
************************************/
DropFirst::DropFirst(TextProcessor *tp, unsigned int n): Editor(tp), n(n) {}


/*********** setSource(istream *) ***********
  Purpose: A method of Class DropFirst
           set input source.
  Return: void
************************************/
void DropFirst::setSource(istream *inp) {tp->setSource(inp);}


/*********** getWord() ***********
  Purpose: A method of Class DropFirst
           get the word and drop the first n letters of the word
  Return: string(word already changed)
************************************/
string DropFirst::getWord() {
	string s = tp->getWord();                      // get the word

  // use istringstream to avoid mutiple different words in s which are separated by space
  istringstream iss(s);
  s = "";
  string temp;

  // A loop to drop the first n letters of words in iss which are separated by space
  while(iss >> temp){
    // is length of the word <= n?
  	if(temp.length() <= n) continue;
  	s = s + temp.substr(n) + " ";
  }
  s = s.substr(0, s.length() - 1);               // drop the space at the end
  return s;                                      // return the word changed
}


/*********** fail() ***********
  Purpose: A method of Class DropFirst
           whether reading input is failed
  Return: true if reading input is failed, otherwise false.
************************************/
bool DropFirst::fail() const { return tp->fail();}
