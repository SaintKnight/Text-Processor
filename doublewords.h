#ifndef __DOUBLEWORDS_H__
#define __DOUBLEWORDS_H__
#include <iostream>
#include <string>
#include "editor.h"

// Class DoubleWords is a concrete decorator

class DoubleWords: public Editor {							 // DoubleWords inherits from Editor
	public:
 		// Constructor
    DoubleWords(TextProcessor *tp);
    // set input source
    void setSource(std::istream *inp);
    // get the word and double the word
    std::string getWord();
    // is reading input fail?
    bool fail() const;
};

#endif