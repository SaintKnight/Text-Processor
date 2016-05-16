#ifndef __DROPFIRST_H__
#define __DROPFIRST_H__
#include <iostream>
#include <string>
#include "editor.h"

// Class DropFirst is a concrete decorator

class DropFirst: public Editor {								 // DropFirst inherits from Editor
// private fields
		// number of letters to drop from the front of the word
    unsigned int n;
	public:
		// Constructor
    DropFirst(TextProcessor *tp, unsigned int n);
    // set input source
    void setSource(std::istream *inp);
    // get the word and drop the first n letters of the word
    std::string getWord();
    // is reading input fail?
    bool fail() const;
};

#endif
