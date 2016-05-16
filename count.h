#ifndef __COUNT_H__
#define __COUNT_H__
#include <iostream>
#include <string>
#include "editor.h"

// Class Count is a concrete decorator

class Count: public Editor {										 // Count inherits from Editor
	// private fields
		// character we count
		char n;
		// when finished counting one word, record the position 
		// which will be used to continue to count the next word.
		int record;
	public:
		// Constructor
		Count(TextProcessor *tp, char n);
		// set input source
		void setSource(std::istream *inp);
		//get the word and count, and change certain character to the number we count.
		std::string getWord();
		// is reading input fail?
		bool fail() const;
};

#endif